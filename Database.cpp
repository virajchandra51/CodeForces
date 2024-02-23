#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        long long n, r;
        cin >> n >> r;

        set<pair<long long, long long> > s;

        int flag = 1;

        for (int i = 0; i < r; i++) // r
        {
            long long id, subjectCode;
            cin >> id >> subjectCode;

            if (s.find({id, subjectCode}) != s.end()) // logr
            {
                flag = 0;
            }

            s.insert({id, subjectCode}); // logr
        }

        cout << "Scenario #" << tt << ": " << (flag == 1 ? "possible" : "impossible") << endl;
    }
    return 0;
}

// tc - O(rlogr) - 10^5~10^6
// sc - O(r)
