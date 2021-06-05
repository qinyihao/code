#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
const int MAXN = 35;
int v, n, a[MAXN], ans;
void DFS(int x, int sum) {
    if (sum > v)
        return;
    if (x > n) {
        ans = max(ans, sum);
        return;
    }
    DFS(x+1,sum+a[x]);
    DFS(x+1,sum);
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d %d",&v,&n);
    for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    DFS(1,0);
    printf("%d\n",v-ans);
    return 0;
}
