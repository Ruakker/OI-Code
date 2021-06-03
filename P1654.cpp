#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

char buff[0x100000], buffer[0x100000], *s, *p;
char *const buf = buff + 100;

bool isname(char ch)
{
    return isdigit(ch) || isalpha(ch) || ch == '_';
}
void remove_backslash(const char *in_, const char *out_)
{
    FILE *in = fopen(in_, "r");
    FILE *out = fopen(out_, "w");
    if (!in || !out) {
        fclose(in);
        fclose(out);
        return;
    }
    while (fgets(buf, 0x80000, in) != NULL) {
        for (s = buf; *s; s++);
        if (s[-1] == '\n')
            *(--s) = '\0';
        if (s[-1] == '\\') {
            s[-1] = '\0';
            fputs(buf, out);
        } else {
            fputs(buf, out);
            fputc('\n', out);
        }
    }
    fclose(in);
    fclose(out);
}

bool string1, string2, comment, ispre;
void remove_comment_and_space()
{
    string1 = string2 = false;
    for (p = buffer, s = buf; *s; s++) {
        // 一堆对注释的特判
        if (!comment && *s == '/' && s[1] == '/')
            break;
        if (!comment && *s == '/' && s[1] == '*') {
            comment = true;
            s += 4;
        }
        if (comment && s[-1] == '/' && s[-2] == '*')
            comment = false;
        if (comment)
            continue;
        // 一堆对字符串的特判
        if (string2 == 0 && *s == '"' && (s[-2] == '\\' || s[-1] != '\\'))
            string1 ^= 1;
        if (string1 == 0 && *s == '\'' && (s[-2] == '\\' || s[-1] != '\\'))
            string2 ^= 1;
        if (string1 == 0 && string2 == 0)
            if (isspace(*s) && !(isname(p[-1]) && isname(s[1])))
                continue;
        *p++ = isspace(*s) ? ' ' : *s;
    }
    if (comment && s[-1] == '/' && s[-2] == '*')
        comment = false;
    *p = '\0';
}

void compress(const char *in_, const char *out_, const char *tmp_, int max_len)
{
    comment = false;
    remove_backslash(in_, tmp_);
    FILE *in = fopen(tmp_, "r");
    FILE *out = fopen(out_, "w");
    if (!in || !out) {
        fclose(in);
        fclose(out);
        return;
    }
    bool ispre = true;
    int cnt = 0;
    buf[-1] = ' ';
    while (fgets(buf + 1, 0x80000, in) != NULL) {
        if (ispre)
            buf[-1] = '\0';
        *buf = ' ';
        remove_comment_and_space();
        if (*buffer == '#' && !ispre) {
            ispre = true;
            fputc('\n', out);
            cnt = 0;
        }
        for (s = buffer; *s; s++, cnt++) {
            if (cnt == max_len - 1) {
                fputc('\\', out);
                fputc('\n', out);
                cnt = 0;
            }
            fputc(*s, out);
        }
        if (*buffer == '#') {
            fputc('\n', out);
            cnt = 0;
        } else if (*buffer)
            ispre = false;

        char *q;
        for (q = buffer; *q; q++);
        buffer[-1] = q[-1];
    }
    fclose(in);
    fclose(out);
    remove(tmp_);
}

char n1[1024], n2[1024], n3[1024];

int main(int argc, char **argv)
{
    tmpnam(n3);
    if (argc == 1) {
        while (1) {
            puts("Enter input filename:");
            gets(n1);
            puts("Enter output filename:");
            gets(n2);
            puts("Enter the maximum number of characters per line:");
            int len = 80;
            scanf("%d", &len);
            compress(n1, n2, n3, len);
            fflush(stdin);
        }
    }
    for (int i = 1; i < argc; i++) {
        const char *in = argv[i], *out = in;
        printf("compressing file '%s'.\n", in);
        int len = 80;
        bool flag1 = 0, flag2 = 0;
        while (i + 1 < argc && argv[i + 1][0] == '-') {
            if (argv[i + 1][1] == 'l') {
                if (flag1) {
                    puts("Error! Repeated -l.");
                    return 1;
                }
                flag1 = 1;
                if (i + 2 == argc || (!isdigit(argv[i + 2][0]) && argv[i + 2][0] != '-')) {
                    puts("Error! Unknown format.");
                    return 1;
                }
                sscanf(argv[i + 2], "%d", &len);
                i += 2;
            } else if (argv[i + 1][1] == 'o') {
                if (flag2) {
                    puts("Error! Repeated -o.");
                    return 1;
                }
                flag2 = 1;
                if (i + 2 == argc) {
                    puts("Error! Unknown format.");
                    return 1;
                }
                out = argv[i + 2];
                i += 2;
            } else {
                puts("Error! Unknown format.");
                return 1;
            }
        }
        compress(in, out, n3, len);
    }
}