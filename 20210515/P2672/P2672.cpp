#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=100010;

typedef long long ll;
typedef unsigned long long ull;

int q[MAXN], h[MAXN], qm[MAXN], n;

struct str {
    int s, v;
}a[MAXN];

bool cmp(str a, str b){
    return a.v > b.v;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i].s);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i].v);
    sort(a+1, a+n+1, cmp);
    for(int i = n; i >= 1; --i)
        h[i] = max(h[i+1], 2*a[i].s + a[i].v);
    for(int i = 1; i <= n; ++i)
        qm[i] = max(qm[i-1],a[i].s);
    for(int i = 1; i <= n; ++i)
        q[i] = q[i-1] + a[i].v;
    for(int i = 1; i <= n; ++i)
        printf("%d\n", max(q[i-1]+h[i], q[i]+ 2*qm[i]));
    return 0;
}