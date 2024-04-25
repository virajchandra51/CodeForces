#include <bits/stdc++.h>
using namespace std;

int helper(int i, int n, vector<pair<int,int>> &a, int W)
{
    if (i >= n)
    {
        if(W>=0)
        return 0;
        return INT_MIN;
    }
    int notTake = helper(i+1,n,a,W);
    int take = a[i].second+helper(i+1,n,a,W-a[i].first);
    return max(take,notTake);
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    cout<<helper(0, n, a, W)<<endl;
    return 0;
}