#include <bits/stdc++.h>
using namespace std;

double helper(int i, double s, int n, vector<int> &a)
{
    if(i==n) return (s*1.0/n*1.0);
    return helper(i+1,s+a[i],n,a);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout<<setprecision(7)<<fixed<<helper(0,0.0,n,a)<<endl;
    return 0;
}