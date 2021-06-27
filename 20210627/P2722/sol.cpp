#include <iostream>
#include <cstdio>
using namespace std;

int n, v, f[10010], c, w;

int main() {
    scanf("%d%d", &v, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w, &c);
        for (int j = c; j <= v; ++j) {
            f[j] = max(f[j], f[j - c] + w);
        }
    }
    printf("%d", f[v]);
    return 0;
}