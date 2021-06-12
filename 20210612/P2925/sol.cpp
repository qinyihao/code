#include<cstdio>

int dp[50005],v[5005];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int c, h;
    scanf("%d%d", &c, &h);
    for(int i = 1;i <= h; ++i)
        scanf("%d", v + i);
    for(int i = 1;i <= h; ++i)
        for(int j = c;j >= v[i]; --j)
            if(dp[j - v[i]] + v[i] > dp[j])
                dp[j] = dp[j - v[i]] + v[i];
    printf("%d\n",dp[c]);
    return 0;
}
