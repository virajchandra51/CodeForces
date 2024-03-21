#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long mid, long long x, long long y, long long n)
{
    if (mid < min(x, y))
        return false;
    long long actualSeconds = mid - min(x, y);
    long long countOfCopies = actualSeconds / x + actualSeconds / y + 1;
    return countOfCopies >= n;
}

int main()
{
    long long n, x, y;
    cin >> n >> x >> y;
    long long low = 1;
    long long high = max(x, y) * n;
    long long ans;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (isPossible(mid,x,y,n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}

// tc - O(log(max(x,y)*n)) ~ log(10^9)
// sc - O(1)