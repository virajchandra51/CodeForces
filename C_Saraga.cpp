#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();

    const int INF = 1e9;
    vector<int> pref(26, INF), suff(26, INF);

    // shortest prefix of S (length >= 2) ending with char c
    for (int i = 1; i < n; i++)
    {
        int c = S[i] - 'a';
        pref[c] = min(pref[c], i + 1);
    }

    // shortest suffix of T (length >= 2) starting with char c
    for (int i = m - 2; i >= 0; i--)
    {
        int c = T[i] - 'a';
        suff[c] = min(suff[c], m - i);
    }

    string ans = "";
    int bestLen = INF;

    for (int c = 0; c < 26; c++)
    {
        if (pref[c] == INF || suff[c] == INF)
            continue;

        int len = pref[c] + suff[c] - 1;
        if (len < bestLen)
        {
            bestLen = len;
            ans = S.substr(0, pref[c]) +
                  T.substr(m - suff[c] + 1);
        }
    }

    if (ans.empty())
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}

// Time Complexity = O(n + m + 26*(n+m)) = O(n + m)
// Space Complexity = O(n + m)