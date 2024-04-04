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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // taking input

        sort(a.begin(), a.end()); // basic sorting // nlogn

        long long opCount = 0;
        for (int i = 0; i < n; i++) // n
            opCount += (abs(a[i] - i));
        // I need to make a[i] = i so add on operation count

        cout << opCount << endl;
    }
    return 0;
}

// tc - O(nlogn) - 2*10^5 * 20 ~ 10^6
// sc - O(N)