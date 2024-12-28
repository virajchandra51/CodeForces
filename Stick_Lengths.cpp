#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];

    sort(a.begin(), a.end()); // nlogn

    double median;

    if (n & 1)
        median = (a[n / 2]);
    else
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    long long answer = 0;

    for (int i = 0; i < n; i++) // n
        answer += abs((a[i] - median));

    cout << answer << endl;

    return 0;
}

// tc = O(nlogn)
// sc = o(n)