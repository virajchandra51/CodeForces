#include <bits/stdc++.h>
using namespace std;

bool checker(long long mid, long long cows[], int n, int k)
{
    long long count_of_stalls = 1;
    long long pointer_index = 0;
    for (int i = 1; i < n; i++) // n
    {
        if (cows[i] - cows[pointer_index] >= mid)
        {
            pointer_index = i;
            count_of_stalls++;
        }
    }
    return count_of_stalls >= k;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    long long cows[n];
    for (int i = 0; i < n; i++)
        cin >> cows[i];

    long long low = INT_MAX;
    for (int i = 1; i < n; i++)
        low = min(low, cows[i] - cows[i - 1]);

    long long high = cows[n - 1] - cows[0];

    long long ans;
    while (low <= high) // O(log2(SS))
    {
        long long mid = (low + high) / 2;
        if (checker(mid, cows, n, k)) // O(n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

// tc - O(n*log2(ss)) - O(10^4*30) = 3*10^5 ~ 10^5
// sc - O(n)