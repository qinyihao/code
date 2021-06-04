#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    char m[111], c[111];
    int n;
    cin >> n;
    ll p;
    for (int i = 1; i <= 300; i++)
    {
        p = i * i;
        int j = 0;
        int b = i;
        int z = 0;
        while (b)
        {
            if (b % n < 10)
                c[z++] = b % n + '0';
            else
                c[z++] = b % n - 10 + 'A';
            b /= n;
        }
        while (p)
        {
            if (p % n < 10)
                m[j++] = p % n + '0';
            else
                m[j++] = p % n - 10 + 'A';
            p /= n;
        }
        int f = 1;
        for (int l = 0, k = j - 1; l < j; l++, k--)
        {
            if (m[l] != m[k])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            for (int l = z - 1; l >= 0; l--)
                cout << c[l];
            cout << " ";
            for (int l = j - 1; l >= 0; l--)
                cout << m[l];
            cout << endl;
        }
    }
    return 0;
}