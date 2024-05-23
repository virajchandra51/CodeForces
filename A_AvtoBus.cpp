#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n < 4 || n % 2 == 1)
        {
            cout << -1 << '\n';
        }
        else
        {
            long long min = n / 6;
            long long a = n % 6;
            if (a != 0)
                min += 1;
            long long max = n / 4;
            cout << min << " " << max << '\n';
        }
    }
    return 0;
}

// tc - O(1)
// sc - O(1)