#include <bits/stdc++.h>
using namespace std;

void helper(int i, int n, vector<int> &a)
{
    if(i==n) return;
    helper(i+1,n,a);
    if(i%2==0) cout<<a[i]<<" "; //imp
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    helper(0,n,a);
    return 0;
}