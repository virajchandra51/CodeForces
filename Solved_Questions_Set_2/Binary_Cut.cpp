#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long c = 1;
        long long n = s.size();
        bool f = false;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                c++;
                if (s[i] == '0' && s[i + 1] == '1')
                    f = true;
            }
        }
        if (f == true)
            c--;
        cout << c << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(1)