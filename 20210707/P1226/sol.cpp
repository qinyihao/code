#include <iostream>
using namespace std;
typedef long long ll;

ll k, b, p, ans;

ll Pow(ll x, ll y, ll z) {
    ll res = 1;
    for(x %= z; y > 0; y /= 2) {
        if(y % 2 == 1)
            res = res * x % z;
        x = x * x % z;
    }
    return res;
}

int main() {
    cin >> b >> p >> k;
    ans = Pow(b, p, k);
    cout << b << "^" << p << " mod " << k << "=" << (ans + k) % k << endl;
    return 0;
}