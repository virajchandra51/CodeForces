#include <bits/stdc++.h>
using namespace std;

long long points(long long r, long long e)
{
    long long p = 0;
    for (long long x = 0; x <= (r + e); x++)
    {
        long long d = (r + e + 1) * (r + e + 1) - x * x;
        long long y;
        long long l = 0;
        long long h = (r + e);
        while (l <= h)
        {
            long long mid = l + (h - l) / 2;
            if (mid * mid < d)
            {
                y = mid;
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        if (x == 0)
            p += (y * 2 + 1);
        else
            p += ((y * 2 + 1) * 2);
    }
    return p;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long r;
        cin >> r;
        long long ans = 0;
        long long p1 = points(r, 0); // rlogr
        long long p2 = points(r, -1); // rlogr
        cout << p1 - p2 << endl;
    }
    return 0;
}

// tc - O(rlogr)
// sc - O(1)