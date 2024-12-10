#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b);

        if (a == b)
        {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        else
        {
            long long gcd = abs(a - b);
            long long answer = min(b % gcd, gcd - b % gcd);
            cout << gcd << " " << answer << endl;
        }
    }
    return 0;
}
