#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        long long j = 0;
        long long k = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = a[i];
            while (j < m && b[j] != ch)
                j++;
            if (j == m)
                break;
            else
            {
                k++;
                j += 1;
            }
        }
        cout << k << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(1)