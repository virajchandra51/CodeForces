#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> prevSum(n, -1);
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                prevSum[i] = prevSum[i - 1];
            else
                prevSum[i] = i - 1;
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (prevSum[r] >= l)
                cout << r + 1 << " " << prevSum[r] + 1 << endl;
            else
                cout << -1 << " " << -1 << endl;
        }
        cout << endl;
    }
    return 0;
}