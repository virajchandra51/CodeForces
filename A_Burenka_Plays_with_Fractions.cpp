#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long g1 = gcd(a, b); // O(log)
        long long g2 = gcd(c, d); // O(log)
        a /= g1;
        b /= g1;
        c /= g2;
        d /= g2;
        long long x = a * d;
        long long y = b * c;
        if (x == y)
            cout << 0 << endl;
        else
        {
            if (x == 0 || y == 0)
                cout << 1 << endl;
            else if (x % y == 0 || y % x == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}

// tc - O(log(max(a,b,c,d)))
// sc - O(log)
