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
        int n = s.size();
        map<char, int> freqMap;
        for (auto it : s)
            freqMap[it]++;  // nlogn
        int ans = INT_MAX;
        for (auto it : freqMap)
        {
            char ch = it.first;
            int freq = it.second;
            int l = 0;
            int r = freq - 1;
            int c = 0;

            for (int i = l; i <= r; i++)
                if (s[i] == ch)
                    c++;
            
            ans = min(ans, freq - c);

            while (r < n)
            {
                if (s[l] == ch)
                    c--;
                l++;
                if (r + 1 < n && s[r + 1] == ch)
                    c++;
                r++;
                ans = min(ans, freq - c);
            }
        } // 26*n
        cout << ans << endl;
    }
    return 0;
}