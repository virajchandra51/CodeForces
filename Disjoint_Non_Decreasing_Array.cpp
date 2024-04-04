#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taking input

        int breakPoint = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                breakPoint = i;
                break;
            }
        }

        if (breakPoint == -1 || breakPoint + 2 >= n) // if array is sorted already
        // or breakpoint exists at n-2 location
        {
            cout << "YES" << endl;
            continue;
        }

        long long lowerLimit = a[breakPoint] - a[breakPoint + 1]; // lower limit
        long long upperLimit = -1;                                // intially -1

        if (breakPoint + 2 < n)
            upperLimit = a[breakPoint + 2] - a[breakPoint + 1]; // if possible now define this

        long long i = breakPoint; // start point

        while (i < n - 1)
        {
            if (a[i] > a[i + 1])
            {
                lowerLimit = max(lowerLimit, a[i] - a[i + 1]);
                if (i + 2 < n)
                    upperLimit = min(upperLimit, a[i + 2] - a[i + 1]);
                i += 2;
            }
            else
            {
                i++;
            }
        }

        if (lowerLimit <= upperLimit)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(n)