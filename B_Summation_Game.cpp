#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        long long sum = 0;
        vector<long long> pre(n, 0);
        pre[0] = a[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + a[i];
        for (int i = 0; i < n; i++)
            sum += a[i];
        long long ans = sum - (2 * pre[x - 1]);
        for (long long i = 0; i < k; i++)
        {
            long long sum1 = pre[i];
            long long sum2 = pre[min(i + x, n - 1)];
            long long sum3 = sum2 - sum1;
            long long sum4 = sum - sum1 - (2 * sum3);
            ans = max(sum4, ans);
        }
        cout << ans << endl;
    }
    return 0;
}