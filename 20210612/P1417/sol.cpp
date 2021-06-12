#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define ll long long
const ll MAXN = 1e5+10;
ll T, n, f[MAXN];

struct node {
    ll a, b, c;
} m[MAXN];

bool cmp(node x, node y) {
    return x.c * y.b < x.b * y.c;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%lld%lld", &T, &n);
    for(ll i = 1; i <= n; ++i)
        std::cin >> m[i].a;
    for(ll i = 1; i <= n; ++i)
        std::cin >> m[i].b;
    for(ll i = 1; i <= n; ++i)
        std::cin >> m[i].c;
    std::sort(m + 1, m + 1 + n, cmp);
    for(ll i = 1; i <= n; ++i)
        for(ll j = T; j >= m[i].c; --j)
            f[j] = max(f[j], f[j-m[i].c] + m[i].a - j * m[i].b);
    ll ans = 0;
    for(ll i = 1; i <= T; ++i)
        ans = max(f[i], ans);
    printf("%lld", ans);
    return 0;
}
