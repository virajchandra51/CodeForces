#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int main()
{
    fastio() int t;
    cin >> t;
    while (t--)
    {
        long long n, k, PB, PS;
        cin >> n >> k >> PB >> PS;
        vector<long long> a(n);
        vector<long long> score(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> score[i];
        vector<long long> pathB;
        vector<long long> pathS;
        vector<long long> vis(n, 0);

        vis[PB - 1] = 1;
        while (true)
        {
            pathB.push_back(score[PB - 1]);
            PB = a[PB - 1];
            if (vis[PB - 1] == 1)
                break;
        } // O(N)

        vis = vector<long long>(n, 0);
        vis[PS - 1] = 1;
        while (true)
        {
            pathS.push_back(score[PS - 1]);
            PS = a[PS - 1];
            if (vis[PS - 1] == 1)
                break;
        } // O(N)

        long long bs = 0, ss = 0;

        long long preSum = 0;

        for (int i = 0; i < pathB.size(); i++) // O(min(pathB.size(),k))
        {
            if (k < i + 1)
                break;
            long long currS = preSum + pathB[i] * (k - i);
            bs = max(bs, currS);
            preSum += pathB[i];
        }

        preSum = 0;

        for (int i = 0; i < pathS.size(); i++) // O(min(pathS.size(),k))
        {
            if (k < i + 1)
                break;
            long long currS = preSum + pathS[i] * (k - i);
            ss = max(ss, currS);
            preSum += pathS[i];
        }

        if (bs > ss)
            cout << "Bodya" << endl;
        else if (ss > bs)
            cout << "Sasha" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(n)