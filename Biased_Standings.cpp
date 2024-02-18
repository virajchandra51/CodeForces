#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {

        long long n;
        cin >> n;

        vector<pair<long long, string> > a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i].second >> a[i].first;

        sort(a.begin(), a.end()); // nlogn

        long long answer = 0;

        for (long long i = 1; i <= n; i++) //n
            answer += (abs(i - a[i - 1].first));
        cout << answer << endl;
    }
    return 0;
}

// TC - O(nlogn + n) ~  O(nlogn)
// SC - O(n)