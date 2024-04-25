#include<bits/stdc++.h>
using namespace std;
bool checker(double &mid,pair<double,double> *arr,int &n)
{
    double left = -1e18,right = 1e18;
    for(int i=0; i<n; i++)
    {
        left = max(left,arr[i].first - (arr[i].second*mid));
        right = min(right,arr[i].first + (arr[i].second*mid));
        if(left>right)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    pair<double,double> arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i].first>>arr[i].second;
    double pres = 1e-7;
    double low = 0, high = 1e9;
    for(int i=0; i<=70; i++)
    {
        double mid = low + (high - low)/2;
        if(checker(mid,arr,n))
        {
            //cout<<mid<<endl;
            high = mid - pres;
        }else{
            low = mid + pres;
        }
    }
    cout<<setprecision(7)<<fixed<<high<<endl;
}