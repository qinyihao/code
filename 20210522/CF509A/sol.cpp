#include <iostream>
using namespace std;
int a[15][15];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        a[i][1]=1;
        a[1][i]=1;
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= n; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    printf("%d", a[n][n]);
    return 0;
}