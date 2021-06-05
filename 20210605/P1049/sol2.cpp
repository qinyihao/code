#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int sum, tot;
int f[20005] = { 0 };
int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    cin >> tot;
    cin >> sum;
    int things[sum + 10];
    for(int i = 1; i <= sum; ++i) {
        cin >> things[i];
    }
    for (int i = 1; i <= sum; ++i) {
        for (int j = tot; j >= things[i]; --j)
            f[j] = max(f[j], f[j - things[i]] + things[i]);
    }
    cout << tot - f[tot] << endl;
    return 0;
}