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
        unordered_map<char, int> mp;
        for (auto it : s) // n
            mp[it]++; // 1
        if (mp.size() == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < s.size() - 1; i++) // n
            {
                if (s[i] != s[i + 1])
                {
                    swap(s[i], s[i + 1]);
                    break;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}

// tc - O(n)
// sc - O(10)