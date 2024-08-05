#include <bits/stdc++.h>
using namespace std;

long long check(long long mid, long long n) // n
{
    long long count = 0;
    for (long long row = 1; row <= n; row++)
        count += min(n, mid / row);
    return count >= (n * n + 1) / 2;
}

int main()
{
    long long t = 1;
    while (t--)
    {
        long long n;
        cin >> n;
        long long ans;
        long long left = 1;
        long long right = n * n;
        while (left <= right) // log(n*n)
        {
            long long mid = left + (right - left) / 2;
            if (check(mid, n))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}

// tc - O(n*log(n*n)) - O(n*log(n^2)) - O(2*n*log(n)) - O(n*log(n)) - O(10^6 * 20) - O(10^7)
// sc - O(1)