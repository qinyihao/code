#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;
#define int long long
int n, m, k, x;
inline int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

inline int ksm(int a, int b, int mod) {
	int ans = 1;
	a = a % mod;
	while(b) {
		if(b & 1)
			ans=(ans*a)%mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;

}

signed main(signed argc, char *argv[]) {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
	scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
	int lcm = n * m / gcd(n, m);
	cout << (ksm(10, k, lcm)* m + x) % n;
	return 0;
}