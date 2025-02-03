#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        long long y = (k * b);
        if (y > s)
            cout << "-1" << endl;
        else
        {
            vector<long long> ans(n, 0);
            ans[0] = y;
            s -= y;
            for (int i = 0; i < n; i++)
            {
                long long add = min(k - 1, s);
                ans[i] += add;
                s -= add;
            }
            if (s > 0)
            {
                cout << "-1" << endl;
            }
            else
            {
                for (long long i = 0; i < n; i++)
                    cout << ans[i] << " ";
                cout << endl;
            }
        }
    }
}