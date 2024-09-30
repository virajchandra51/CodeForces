#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long operations = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] <= a[i + 1])
            {
                long long diff = a[i + 1] - a[i];
                long long required_operations = diff / 2 + 1;
                operations = min(operations, required_operations);
            }
            else
                operations = 0;
        }

        cout << operations << endl;
    }
    return 0;
}