#include <bits/stdc++.h>
using namespace std;

bool checker(double ropeSize, vector<int> &ropes, int totalRopes)
{
    long long pieces = 0;
    for (auto i : ropes)
    {
        pieces += (i / ropeSize); // division
        if (pieces >= totalRopes)
            return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double error = 1e-7;
    double left = 0;
    double right = 1e7;
    double ans;

    // O(log2(SS)) = iterations - 10^14 - 50

    int count = 0;
    // cout << setprecision(17) << fixed << endl;
    for (int i = 0; i < 50; i++)
    {
        double mid = (left + right) / 2;
        if (checker(mid, arr, k))
        {
            ans = mid;
            left = mid + error;
        }
        else
        {
            right = mid - error;
        }
        // cout << left << " " << mid << " " << right << endl;
    }

    cout << setprecision(7) << fixed << ans << endl;

    return 0;
}