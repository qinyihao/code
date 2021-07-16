#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[100005][21], m, n;

void rmq_st() {
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i <=m; i++)
            if(i + (1 << j) - 1 <= m)
                dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &dp[i][0]);
    rmq_st();
    while(n--) {
        int l, r, k;
        scanf("%d%d", &l, &r);
        k =log2(r - l + 1);
        printf("%d ", min(dp[l][k], dp[r - (1 << k) + 1][k]));
    }
    return 0;
}