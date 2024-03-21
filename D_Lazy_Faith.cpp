#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, q;
    cin >> a >> b >> q;
    vector<long long> shrines(a), temples(b);
    for (long long i = 0; i < a; i++)
        cin >> shrines[i];
    for (long long i = 0; i < b; i++)
        cin >> temples[i];

    sort(shrines.begin(), shrines.end());
    sort(temples.begin(), temples.end());

    for (long long i = 0; i < q; i++)
    {
        long long x;
        cin >> x;
        long long answer = INT_MAX;
        auto it = upper_bound(shrines.begin(), shrines.end(),x) - shrines.begin();
        if(it!=a)
        {
            
        }
    }

    return 0;
}

// TC - O(n)
// SC - O(n)