#include <cstdio>
#define max(a, b) ((a) > (b) ? (a) : (b))
int n, a[200100], f[200100], sum = -0x7fffffff;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = max(f[i - 1] + a[i], a[i]);
        sum = max(sum, f[i]);
    }
    printf("%d", sum);
    return 0;
}
