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
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        long long m = *min_element(arr.begin(), arr.end());
        vector<long long> sortable;

        for (auto it : arr)
        {
            if (it % m == 0)
                sortable.push_back(it);
        }

        sort(sortable.begin(), sortable.end());

        for (long long i = 0, j = 0; i < n; i++)
        {
            if (arr[i] % m == 0)
                arr[i] = sortable[j++];
        }

        vector<long long> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        if (sortedArr == arr)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)