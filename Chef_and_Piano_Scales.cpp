#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1e9+7
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<int>

using namespace std;

void solve()
{
int n;
	    string str;
	    cin>>str;
	    cin>>n;
	    n = n*12;
	    int sz = str.length();
	    int cnt = 0;
	    for(int i=0; i<sz; i++){
	        if(str[i] == 'T'){
	            cnt += 2;
	        }
	        else{
	            cnt += 1;
	        }
	    }
	    int ans = 0;
	    for(int i=1; i<100001; i++){
	        int z = cnt*i + 1;
	        if(z <= n){
	            ans += n-z+1; 
	        }
	        else{
	            break;
	        }
	    }
	    cout<<ans<<endl;
}


int32_t main()
{
    fast
    //Rating? Neh. In love with experience.
    //Code Karlo, Coz KHNH :)
    int t;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;
}