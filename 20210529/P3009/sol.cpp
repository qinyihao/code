#include <iostream>
#include <fstream>
using namespace std;

int n, a[100100], f[100100], ans = -1e9;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = max(f[i - 1] + a[i], a[i]);
        ans = max(ans, f[i]); 
    }
    printf("%d", ans);
    return 0;
}