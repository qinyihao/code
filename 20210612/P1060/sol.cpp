#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m, w[30], v[30], f[30100];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &w[i], &v[i]);
        v[i] *= w[i];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 0; --j)
            if (j >= w[i])
                f[j] = max(f[j], f[j - w[i]] + v[i]);
    printf("%d", f[m]);
    return 0;
}
