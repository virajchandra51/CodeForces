#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(b, b + n, a[i]);
            int ind = distance(b, it);
            cout << b[ind] - a[i] << " ";
        }
        cout << endl;
        int ind = n - 1;
        ans[n - 1] = ind;
        for (int i = n - 2; i >= 0; i--)
        {
            if (b[i] < a[i+1])
            {
                ind = i;
            }
            ans[i] = ind;
        }
        // for(auto it:ans ) cout<<it<<" ";
        // cout<<endl;
        for (int i = 0; i < n; i++)
        {
            cout << b[ans[i]] - a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}