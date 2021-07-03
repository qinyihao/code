#include <iostream>

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x;
}
int a[105];
bool dp[105][10005];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int n = read();
    int tot = 0;
    for(int i = 1; i <= n; i++)
        a[i] = read(), tot += a[i];
    dp[0][0] = true;
    for(int i = 1; i <= n; i++)
        for(int j = i; j >= 1; j--)
            for(int k = tot; k >= a[i]; k--)
                dp[j][k] |= dp[j - 1][k - a[i]];
    for(int i = tot / 2; i >= 0; i--)
        if(dp[n / 2][i]) {
            printf("%d", i);
            return 0;
        }
    return 0;
}