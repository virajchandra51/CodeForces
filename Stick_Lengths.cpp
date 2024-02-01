#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // taking input

    sort(a.begin(), a.end()); // o(nlogn)

    double median;

    if(n&1)
        median = (a[n / 2]);
    else
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    ll answer = 0;

    for (int i = 0; i < n; i++)
        answer += abs((a[i] - median));

    cout << answer << endl;

    return 0;
}

// TC - O(nlogn)
// SC - O(1)