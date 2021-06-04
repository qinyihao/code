#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const int maxn = 200100;
const ll mod = 1000000007;

int n, m, block, bel[maxn], cnt, L[maxn], R[maxn];
ll a[maxn], sum[maxn], pre[500][500], suf[500][500];

inline void update(int x, int y, ll z) {
    if (x >= block) {
        for (int i = y; i <= n; i += x) {
            a[i] += z;
            sum[bel[i]] += z;
        }
        return;
    }
    for (int i = y; i <= x; ++i) {
        pre[x][i] += z;
    }
    for (int i = 1; i <= y; ++i) {
        suf[x][i] += z;
    }
}

inline ll sum_block(int l, int r) {
    ll ans = 0;
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; ++i) {
            ans += a[i];
        }
        return ans;
    }
    for (int i = l; i <= R[bel[l]]; ++i) {
        ans += a[i];
    }
    for (int i = L[bel[r]]; i <= r; ++i) {
        ans += a[i];
    }
    for (int i = bel[l] + 1; i < bel[r]; ++i) {
        ans += sum[i];
    }
    return ans;
}

inline ll query(int l, int r) {
    ll ans = sum_block(l, r);
    for (int i = 1; i < block; ++i) {
        int lb = (l - 1) / i + 1, rb = (r - 1) / i + 1;
        if (lb == rb) {
            ans -= pre[i][(l - 1) % i];
            ans += pre[i][(r - 1) % i + 1];
        } else {
            ans += ll(rb - lb - 1) * pre[i][i] + pre[i][(r - 1) % i + 1] + suf[i][(l - 1) % i + 1];
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    block = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        bel[i] = (i - 1) / block + 1;
        scanf("%lld", &a[i]);
    }
    cnt = bel[n];
    for (int i = 1; i <= cnt; ++i) {
        L[i] = R[i - 1] + 1;
        R[i] = i * block;
    }
    R[cnt] = n;
    for (int i = 1; i <= cnt; ++i) {
        for (int j = L[i]; j <= R[i]; ++j) {
            sum[i] += a[j];
        }
    }
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y;
            ll z;
            scanf("%d%d%lld", &x, &y, &z);
            update(x, y, z);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r) % mod);
        }
    }
    return 0;
}