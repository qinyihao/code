#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, i, j, k, ans, x, y, z;
int a[10005][105][3];
int s[10005];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            scanf("%d%d", &a[i][j][1], &a[i][j][2]);
            s[i] = s[i] + a[i][j][1];
        }
    scanf("%d", &x);
    x = x % m + 1;
    ans = 0;
    for (i = 1; i <= n; i++) {
        ans = (ans + a[i][x][2]) % 20123;
        if (i == n)
            break;
        z = x;
        a[i][x][2] = a[i][x][2] % s[i];
        if (a[i][x][2] == 0)
            a[i][x][2] = s[i];
        y = a[i][x][1];
        while (y < a[i][z][2]) {
            x = x % m + 1;
            y = y + a[i][x][1];
        }
    }
    printf("%d", ans);
}