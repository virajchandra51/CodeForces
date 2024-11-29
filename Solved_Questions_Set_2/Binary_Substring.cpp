#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // taking input

        unordered_map<int, int> stringCategories;
        for (int i = 0; i < n; i += 2) // n/2 ~ n
        {
            if (s[i] == '0' && s[i + 1] == '0')
                stringCategories[0]++; // 1
            else if (s[i] == '1' && s[i + 1] == '1')
                stringCategories[1]++; // 1
            else if (s[i] == '0' && s[i + 1] == '1')
                stringCategories[2]++; // 1
            else
                stringCategories[3]++; // 1
        }
        /// 10 first, then 00s, then 01, then 11s, then 10 left over (ideal)

        // lets put all 00s and 11s
        int maxLength = 2 * stringCategories[0] + 2 * stringCategories[1];

        if (stringCategories[2] > 0) // add that 01 in between 00s and 11s
            maxLength += 2;

        if (stringCategories[3] > 0) // add that 10 at the start
        {
            maxLength++;
            stringCategories[3]--;
            if (stringCategories[3] > 0) // if possible now add 10 at end too
            {
                maxLength++;
            }
        }

        cout << maxLength << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(1)