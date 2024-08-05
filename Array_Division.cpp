#include <bits/stdc++.h>
using namespace std;

long long check(long long maxsum, vector<long long> &arr, long long k, long long n)
{
    long long sum = 0;
    long long count = 1;
    for (long long i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxsum)
        {
            count++;
            sum = arr[i];
        }
    }
    return (count <= k);
}

int main()
{
    long long t = 1;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        // cout<<sum<<endl;
        long long right = sum;
        long long ans = 0;
        long long left = *max_element(arr.begin(), arr.end());
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (check(mid, arr, k, n))
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