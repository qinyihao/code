#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 50
#define INF 2147483647
int n, m, bx, by, bf, minn[N][N][4], ans = INF;
char ma[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int read() {
	int w = 0, f = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		w = (w << 3) + (w << 1) + (c ^ 48);
		c = getchar();
	}
	return w * f;
}

void dfs(int x, int y, int f, int now) {
	if (ma[x][y] == 'F') {
		ans = min(ans, now);
		return;
	}
	if (now >= minn[x][y][f] || now >= ans)
		return;
	minn[x][y][f] = now;
	bool pd = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (f == i && ma[xx][yy] != '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m)
			dfs(xx, yy, f, now), pd = 0;
	}
	f = (f + 1) % 4;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (f == i && ma[xx][yy] != '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m)
			dfs(xx, yy, f, now + 5), pd = 0;
	}
	f = (f + 6) % 4;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (f == i && ma[xx][yy] != '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m)
			dfs(xx, yy, f, now + 1), pd = 0;
	}
	if (pd) {
		f = (f + 3) % 4;
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (f == i && ma[xx][yy] != '.' && xx >= 1 && xx <= n && yy >= 1 && yy <= m)
				dfs(xx, yy, f, now + 10), pd = 0;
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	memset(minn, 63, sizeof(minn));
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		scanf("%s", ma[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (ma[i][j] == 'N')
				bx = i, by = j, bf = 0;
			if (ma[i][j] == 'E')
				bx = i, by = j, bf = 1;
			if (ma[i][j] == 'S')
				bx = i, by = j, bf = 2;
			if (ma[i][j] == 'W')
				bx = i, by = j, bf = 3;
		}
	}
	dfs(bx, by, bf, 0);
	printf("%d\n", ans);
	return 0;
}