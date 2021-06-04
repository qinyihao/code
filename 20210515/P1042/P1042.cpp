#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
const int MAXN = 100005;

string s[MAXN];
int a[MAXN], b[MAXN], a2[MAXN], b2[MAXN];

bool check(int x) {
    int t = s[x].size();
    for(int i = 0; i < t; i++) {
        if(s[x][i] == 'E')
            return 0;
    }
    return 1;
}

int solve() {
    int n = 1, i = 0, j = 0, t = 1, t2 = 1;
    cin >> s[n];
    while(check(n)) {
        ++n;
        cin >> s[n];
    }
    for(int i = 1; i <= n; ++i) {
        int sz = s[i].size();
        for(int j = 0; j < sz; ++j) {
            if(s[i][j] == 'E') {
                for(int i = 1; i <= t; ++i)
                    cout << a[i] << ":" << b[i] <<endl;
                cout << endl;
                for(int i = 1; i <= t2; ++i)
                    cout << a2[i] << ":" << b2[i] <<endl;
                return 0;
            }
            if(s[i][j] == 'W'){
                ++a[t];
                ++a2[t2];
            } else if(s[i][j] == 'L') {
                ++b[t];
                ++b2[t2];
            }
            if((a[t] >= 11 || b[t] >= 11) && abs(a[t] - b[t]) >= 2)
                ++t;
            if((a2[t2] >= 21 || b2[t2] >= 21) && abs(a2[t2] - b2[t2]) >= 2)
                ++t2;            
        }
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w", stdout);
    #endif
    solve();
}