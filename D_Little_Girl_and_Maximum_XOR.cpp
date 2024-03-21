#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int main()
{
    ll l, r;
    cin >> l >> r;
    if (l == r)
    {
        cout << 0 << endl;
        return 0;
    }
    ll x = l^r;
    ll i = 0;
    ll ans;
    while (x > 0)
    {
        if (x&1)
            ans = i;
        i++;
        x >>= 1;
    }
    cout << (1ll << (ans + 1)) - 1;
    return 0;
}
