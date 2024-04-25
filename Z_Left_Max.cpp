#include <bits/stdc++.h>
using namespace std;

void helper(int i, int mx, int n, vector<int> &a)
{
    if(i==n) return;
    mx = max(mx,a[i]);
    cout<<mx<<" ";
    helper(i+1,mx,n,a);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    helper(0,INT_MIN,n,a);
    return 0;
}