#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[2017][2017];
int a[2017][2017];
int minn = 1000000000;
int m, n;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[1][i] = a[i][1];
    for (int i = 2; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (j == 1)
                f[i][j] = min(f[i - 1][n], f[i - 1][j]) + a[j][i];
            else
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + a[j][i];
        }
    for (int i = 1; i <= n; i++)
        minn = min(minn, f[m][i]);
    cout << minn << endl;
    return 0;
}
