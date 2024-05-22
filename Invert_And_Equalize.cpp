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
        string s;
        cin >> s;
        long long c1 = 0;
        long long c0 = 0;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (s[0] == '0')
            c0++;
        else
            c1++;
        for (int i = 1; i < n; i++) // n
        {
            if (s[i] != s[i - 1])
            {
                if (s[i] == '1')
                    c1++;
                else
                    c0++;
            }
        }
        cout << min(c1, c0) << endl;

        // tc - O(n)
        // sc - O(1)
    }
    return 0;
}