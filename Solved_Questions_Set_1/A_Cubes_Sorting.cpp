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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i]; // taking input

        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] <= a[i + 1]) // ik if this is true array is not dec or arr in not unique
                flag = false;
        }

        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

// TC - O(n)
// SC - O(1)