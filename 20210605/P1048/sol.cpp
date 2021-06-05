#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int T, M, t[1005], v[1005];
int f[1005] = { 0 };
int main() {
    #ifndef ONLINE_JUDGE
    freopen("medic.in", "r", stdin);
    freopen("medic.out", "w", stdout);
    #endif
    std::cin >> T >> M;
    for (int i = 1; i <= M; ++i)
        scanf("%d%d", &t[i], &v[i]);
    for (int i = 1; i <= M; ++i) {
        for (int j = T; j >= t[i]; --j)
            f[j] = std::max(f[j], f[j - t[i]] + v[i]);
    }
    std::cout << f[T] << std::endl;
    return 0;
}