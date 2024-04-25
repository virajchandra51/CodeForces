#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int low = i;
        int high = n - 1;
        int books;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid] <= t + v[i])
            {
                books = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        ans = max(ans, books - i);
    }
    if (v[n - 1] <= t)
        ans = n;
    cout << ans << " ";
}