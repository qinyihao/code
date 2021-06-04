#include <iostream>
#include <map>
#include <cmath>
using namespace std;
string s, s1, s2;
int n, m, f[110][110], a[110][110];
map <string,int> ma;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        cin >> s;
        ma[s] = i;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> s1 >> s2;
        a[ma[s1]][ma[s2]] = 1;
        a[ma[s2]][ma[s1]] = 1;
    }
    f[1][1] = 1;
    for(int i = 1; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            for(int k = 1; k < j; ++k) {
                if(a[k][j] > 0 && f[i][k] > 0) {
                    f[i][j] = max(f[i][j], f[i][k] + 1);
                }
            f[j][i] = f[i][j];
            }
        }
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        if(a[i][n]) {
            ans = max(ans, f[i][n]);
        }
    }
    printf("%d", ans);
    return 0;
}