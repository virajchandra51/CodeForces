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
        string s;
        cin >> s;
        int zc = 0, oc = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (s[i] == '0')
                    zc++;
                else
                    oc++;
            }
        }
        cout << max(zc, oc) << endl;
    }
    return 0;
}
//TC - O(n)
//SC - O(1)