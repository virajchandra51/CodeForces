#include <bits/stdc++.h>
using namespace std;

bool checker(vector<double> &c, int k, int n)
{
    double sum = 0;
    sort(c.begin(), c.end());
    for (int i = 0; i < k; i++)
        sum += c[n - i - 1];
    return sum>=0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<double, double> > arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    double error = 1e-7;
    double left = error;
    double right = 1e6;
    double ans;
    // log2(SS) -  (10^13) - 60

    for (int iterations = 0; iterations < 60; iterations++)
    {
        double mid = (left + right) / 2;
        vector<double> c(n);
        for (int i = 0; i < n; i++)
        {
            c[i] = arr[i].first - mid * arr[i].second;
        }
        if (checker(c, k, n))
        {
            ans = mid;
            left = mid + error;
        }
        else
        {
            right = mid - error;
        }
    }
    cout << setprecision(7) << fixed << ans << endl;
    return 0;
}