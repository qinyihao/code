#include <iostream>
#include <fstream>
using namespace std;
int n, d[30005], f[30005][3]; 

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
	cin >> n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &d[i]);
	f[1][2 - d[1]] = 1;
    f[1][d[1] - 1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (d[i] == 1) {
			f[i][0] = f[i - 1][0];
			f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
		}
		else {
			f[i][0] = f[i - 1][0] + 1;
			f[i][1] = min(f[i - 1][1], f[i - 1][0]);
		}
	}
	cout << min(f[n][0], f[n][1]);
	return 0;
}