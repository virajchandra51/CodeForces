#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long maxValue = -1;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        maxValue = max(maxValue, a[i]);
    }
    cout << max(maxValue * 2, sum) << endl;
    return 0;
}