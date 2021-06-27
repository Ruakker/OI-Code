#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
#ifdef DEBUG
using std::endl;
#else
#define endl '\n'
#endif
#define int long long

const int N = 10, P = 1e9 + 7;
class matrix {
   private:
    int n, m;
    std::vector<std::vector<long long>> val;
   
   public:
    matrix(int a, int b) {
        n = a, m = b;
        val.resize(a + 1, std::vector<long long>(b + 1));
    }
    
    std::vector<long long> &operator[](const int &x) { return val[x]; }
    const std::vector<long long> &operator[](const int &x) const { return val[x]; }

    matrix operator*(const matrix &Other) {
        matrix res(2, 2);
        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= 2; ++j)
                for (int k = 1; k <= 2; ++k)
                    (res[i][j] += val[i][k] * Other[k][j] % P) %= P;
        return res;
    }
}M(2, 2), I(2, 2);
long long n;
inline void qpow(matrix &a, int k) {
    for (; k; k >>= 1, I = I * I)
        if (k & 1) a = a * I;
}
signed main(){
    std::ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << 1 <<endl;
        return 0;
    }
    M[1][1] = M[1][2] = 1;
    I[1][1] = I[1][2] = I[2][1] = 1;
    I[2][2] = 0;
    qpow(M, n - 2);
    cout << M[1][1] << endl;
    return 0;
}
