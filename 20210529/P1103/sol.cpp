#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int n, k, m, Min = 0x7fffffff;
int f[501][501];

struct info {
	int h, w;
} a[1001];

bool cmp(const info & x, const info & y) {
	return x.h < y.h;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
	std::cin >> n >> k;
	m = n - k;
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].h, &a[i].w);
		
	std::sort(a+1, a+n+1, cmp);
	memset(f, 20, sizeof(f));
	
	for(int i = 1; i <= n; i++)
		f[i][1] = 0;
	 
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i-1; j++)
			for(int l = 2; l <= std::min(i, m); l++)
				f[i][l] = std::min(f[i][l], f[j][l-1] + abs(a[i].w - a[j].w));
		
	for(int i = m; i <= n; i++)
		Min = std::min(Min, f[i][m]);
	
	printf("%d\n", Min);
	return 0;
}