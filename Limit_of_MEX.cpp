#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long &v : arr)
            cin >> v;
        stack<long long> st1, st2;
        vector<long long> nge(n, n);
        vector<long long> pge(n, -1);
        for (long long i = n - 1; i >= 0; i--)
        {
            while (!st1.empty() and arr[st1.top()] <= arr[i])
                st1.pop();
            if (!st1.empty())
                nge[i] = st1.top();
            st1.push(i);
        } // O(n)
        for (long long i = 0; i < n; i++)
        {
            while (!st2.empty() and arr[st2.top()] < arr[i])
                st2.pop();
            if (!st2.empty())
                pge[i] = st2.top();
            st2.push(i);
        } // O(n)

        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            // maximum contribution
            long long left = (i - pge[i]), right = (nge[i] - i);
            ans += arr[i] * left * right;
        } // O(n)

        unordered_map<long long, long long> last;

        for (long long i = 0; i < n; i++)
        {
            long long left = (i - pge[i]), right = (nge[i] - i);
            long long cnt = 0;

            // substraction contribution
            right = (n - nge[i]);
            cnt += right * left;
            if (last.count(arr[i]) == 0)
                last[arr[i]] = -1;
            left = (pge[i] - last[arr[i]]);
            cnt += left * (n - i);
            ans -= cnt;
            last[arr[i]] = i;
        } // O(n)
        cout << ans << endl;
        // tc - O(n)
        // sc - O(n)
    }
    return 0;
}