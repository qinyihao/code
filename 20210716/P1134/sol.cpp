#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
typedef long long ll;
ll result = 1, n;
const int MAXN = 100000000;
int main(int argc, char *argv[]) {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		result *= i;
		while(result % 10 == 0)
			result /= 10;
		result %= MAXN;
	}
	std::cout << result % 10;
	return 0;
}

//2 ^ (sum_of_2 - sum_of_5) * others % 10