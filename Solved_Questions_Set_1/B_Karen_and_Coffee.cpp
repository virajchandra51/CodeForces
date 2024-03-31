#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k, q;
    cin >> n >> k >> q;

    vector<long long> range(200001, 0);
    for (long long i = 0; i < n; i++) // n
    {
        long long l, r;
        cin >> l >> r;
        range[l]++;
        range[r + 1]--;
    }

    for (int i = 1; i <= 200000; i++) // 10^5
        range[i] += range[i - 1];
    

    for (int i = 1; i <= 200000; i++) // 10^5
    {
        if (range[i] >= k)
            range[i] = 1;
        else
            range[i] = 0;
    }


    for (int i = 1; i <= 200000; i++) //10^5
        range[i] += range[i - 1];
    
    for (int i = 0; i < q; i++) // q
    {
        long long a, b;
        cin >> a >> b;
        cout << range[b] - range[a - 1] << endl;
    }

    return 0;
}

// tc - O(n+10^5+q) - 10^5~10^6
// sc - O(2*10^5)
