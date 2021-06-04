#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, cur;
ll f[2][1 << 15], ans[110][110];

ll solve(int n, int m) {
    if (m > n) {
        swap(m, n);
    }
    memset(f, 0, sizeof(f));
    cur = 0;
    f[0][(1 << m) - 1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cur ^= 1;
            memset(f[cur], 0, sizeof(f[cur]));
            for (int k = 0; k < (1 << m); ++k) {
                if (k & (1 << (m - 1))) {
                    f[cur][(k << 1) ^ (1 << m)] += f[cur ^ 1][k];
                }
                if (i && !(k & (1 << (m - 1)))) {
                    f[cur][(k << 1) | 1] += f[cur ^ 1][k];
                }
                if (j && !(k & 1) && (k & (1 << (m - 1)))) {
                    f[cur][((k << 1) | 3) ^ (1 << m)] += f[cur ^ 1][k];
                }
            }
        }
    }
    return f[cur][(1 << m) - 1];
}

int main() {
    memset(ans, -1, sizeof(ans));
    while (scanf("%d%d", &n, &m) == 2) {
        if (ans[n][m] == -1) {
            ans[n][m] = solve(n, m);
        }
        printf("%lld\n", ans[n][m]);
    }
    return 0;
}