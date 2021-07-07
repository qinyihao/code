#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int ans = 0;
char mapp[505][505];
int vis[505][505];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool flag;
void dfs(int x, int y) {
    if (mapp[x][y] == '*')
        return;
    if (x < 1 || x > n || y < 1 || y > m) {
        ans = 0;
        flag = false;
        return;
    }
    vis[x][y] = 1;
    ans++;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!vis[nx][ny])
            dfs(nx, ny);
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    while (cin >> n >> m) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> mapp[i][j];
        int re = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mapp[i][j] == '0' && vis[i][j] == 0) {
                    ans = 0;
                    flag = true;
                    dfs(i, j);
                    if (flag)
                        re += ans;
                }
            }
        }
        printf("%d\n", re);
    }
    return 0;
}