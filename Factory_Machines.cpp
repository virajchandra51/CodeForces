#include <bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<long long> arr, long long t)
{
    long long tasks = 0;
    for (long long i = 0; i < arr.size(); i++)
    {
        tasks += (mid / arr[i]);
        if (tasks >= t)
        {
            return true;
        }
    }
    return (tasks >= t);
}

void solve()
{
    long long n, t;
    cin >> n >> t;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long h = (long long)1e18;
    //*max_element(all(arr))*t;
    // cout<<h<<endl;
    long long l = 0;
    long long ans = 0;
    while (h >= l)
    {
        long long mid = l + ((h - l) / 2);
        bool c = check(mid, arr, t);
        // cout<<l<<" "<<h<<" "<<mid<<" "<<((c)?"t":"f")<<endl;
        if (c)
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------*/
signed main()
{
    long long t = 1;
    // cin>>t;
    for (long long i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}