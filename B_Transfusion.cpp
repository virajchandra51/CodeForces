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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) // n
            cin >> a[i];
            
        long long sum_odd = 0;
        long long sum_even = 0;
        for (int i = 0; i < n; i++) // n
        {
            if (i % 2 == 0)
                sum_even += a[i];
            else
                sum_odd += a[i];
        }

        long long odd_places = n / 2;
        long long even_places = (n + 1) / 2;

        if (sum_odd % odd_places == 0 && sum_even % even_places == 0 && sum_odd / odd_places == sum_even / even_places)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// tc - O(n)
// sc - O(n)