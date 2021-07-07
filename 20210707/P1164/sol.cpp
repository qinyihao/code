#include <cstdio>
int n, m, a[105], f[105][10050];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (j == a[i])
                f[i][j] = f[i - 1][j] + 1;
            else if (j < a[i])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
        }
    }
    printf("%d", f[n][m]);
    return 0;
}