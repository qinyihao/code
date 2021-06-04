#include <iostream>
#include <fstream>
using namespace std;
int n, m, sum, s;
int ans[60];
bool all, flag;
bool a[60][60], vis[60];
void dfs(int k, int cnt)
{
    if (flag == true)
        return;
    ans[cnt] = k;
    if (cnt == n && a[k][s] == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        flag = true;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[k][i] && k != i && !vis[i])
        {
            vis[i] = 1;
            dfs(i, cnt + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 3; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        s = i;
        vis[i] = 1;
        dfs(i, 1);
    }
    return 0;
}