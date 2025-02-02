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
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) // n
            cin >> a[i];
        vector<long long> b(n);
        for (long long i = 0; i < n; i++) // n
            cin >> b[i];

        unordered_map<long long, long long> longest_subarray_a;
        unordered_map<long long, long long> longest_subarray_b;

        long long counter = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
                counter++;
            else
            {
                longest_subarray_a[a[i - 1]] = max(longest_subarray_a[a[i - 1]], counter);
                counter = 1;
            }
        }
        longest_subarray_a[a[n - 1]] = max(longest_subarray_a[a[n - 1]], counter);

        counter = 1;

        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
                counter++;
            else
            {
                longest_subarray_b[b[i - 1]] = max(longest_subarray_b[b[i - 1]], counter);
                counter = 1;
            }
        }
        longest_subarray_b[b[n - 1]] = max(longest_subarray_b[b[n - 1]], counter);

        long long max_freq = -1;
        for (auto i : longest_subarray_a)
            max_freq = max(max_freq, i.second + longest_subarray_b[i.first]);

        for (auto i : longest_subarray_b)
            max_freq = max(max_freq, i.second + longest_subarray_a[i.first]);

        cout << max_freq << endl;
    }
    return 0;
}