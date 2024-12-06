#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i]; // 10
        
        long long x = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (a[i].size() <= m)
            {
                m -= a[i].size();
                x++;
            }
            else
                break;
        }
        cout << x << endl;
    }
    return 0;
}

// tc - O(500)
// sc - O(500)