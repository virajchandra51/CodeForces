#include <bits/stdc++.h>
using namespace std;

long double leftIndex;
long double rightIndex;

bool checker(vector<long double> &transformed_array, long double d, long double n)
{
    vector<long double> prefix_sum(n);
    vector<pair<long double, long double> > min_prefix_sum(n);
    prefix_sum[0] = transformed_array[0];
    min_prefix_sum[0] = {prefix_sum[0], 0};
    
    for (long double i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + transformed_array[i];
        if (prefix_sum[i] < min_prefix_sum[i - 1].first)
            min_prefix_sum[i] = {prefix_sum[i], i};
        else
            min_prefix_sum[i] = min_prefix_sum[i - 1];
    }

    for (long double i = d - 1; i < n; i++)
    {
        if (i - d >= 0 && prefix_sum[i] - min_prefix_sum[i - d].first >= 0)
        {
            leftIndex = min_prefix_sum[i - d].second + 1;
            rightIndex = i;
            return true;
        }
        else
        {
            if (prefix_sum[i] >= 0)
            {
                leftIndex = 0;
                rightIndex = i;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    long double n, d;
    cin >> n >> d;
    vector<long double> arr(n);
    for (long double i = 0; i < n; i++)
        cin >> arr[i];

    long double left = 0;
    long double right = 100;
    long double iterations = 110;

    for (long double it = 0; it < iterations; it++)
    {
        long double mid = (left + right) / 2;
        vector<long double> transformed_array(n);
        for (long double i = 0; i < n; i++)
            transformed_array[i] = arr[i] - mid;
        if (checker(transformed_array, d, n))
            left = mid;
        else
            right = mid;
    }
    // cout << setprecision(7) << fixed << left << endl;
    cout << leftIndex + 1 << " " << rightIndex + 1 << endl;
    return 0;
}