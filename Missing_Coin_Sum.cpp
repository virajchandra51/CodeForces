#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); //nlogn

    if(v[0]!=1)
    {
        cout<<1<<endl; // base case
    }
    else
    {
        long long minCoinSum = 0;
        long long maxCoinSum = 1;
        for(int i=1;i<v.size();i++) //n
        {
            long long newMinCoinSum = minCoinSum+v[i];
            long long newMaxCoinSum = maxCoinSum+v[i];
            if(newMinCoinSum-maxCoinSum>1)
            {
                break;
            }
            maxCoinSum = max(maxCoinSum,newMaxCoinSum);
        }
        cout<<maxCoinSum+1<<endl;
    }
    return 0;
}

// O(nlogn) ~ 10^5-10^6
// O(n)
