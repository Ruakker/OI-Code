#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n, x[1000010], f[1000010];
int main() {
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	int i, j;
	scanf("%d", &n);
	x[1] = 1;
	for (i = 2; i <= n; i++)
		if (!x[i])
			for (j = i; j <= n; j += i)
				if (!f[j])
					x[j] = i;
	for (i = 1; i <= n; i++)
		if (x[i] == i)
			if (i % 3 == 1)
				f[i] = 1;
			else
				f[i] = -1;
		else
			f[i] = f[x[i]] * f[i / x[i]];
	for (i = 1; i <= n; i++)
		printf("%d ", f[i]);
	printf("\n");
	return 0;
}
