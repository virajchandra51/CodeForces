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

        vector<long long> second_elements;
        long long overall_minimum = INT_MAX;

        for (int i = 0; i < n; i++) // n
        {
            long long m;
            cin >> m;
            vector<long long> a(m);
            for (auto &x : a)
                cin >> x;
            
            sort(a.begin(), a.end());
            
            second_elements.push_back(a[1]);
            overall_minimum = min(overall_minimum, a[0]);
        }

        sort(second_elements.begin(), second_elements.end());

        long long sum_of_second_elements = accumulate(second_elements.begin(), second_elements.end(), 0LL);
        long long second_minimum = second_elements[0];

        long long answer = overall_minimum + sum_of_second_elements - second_minimum;
        cout << answer << endl;
    }
    return 0;
}

// tc - O(n*mlog2m + nlog2n) ~ O(10^6)
// sc - O(n)