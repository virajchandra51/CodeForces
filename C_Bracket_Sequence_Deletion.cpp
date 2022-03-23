#include <bits/stdc++.h>

#define pi (3.141592653589)
#define M 1000000007
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
    string s;
    cin>>n;
    cin>>s;

  int i=0;
  int res = 0;
  for(i=0;i<n-1;) {
    if (s[i] == s[i + 1]) {
      res++;
      i += 2;
      continue;
    }
    if (s[i] == '(' && s[i + 1] == ')') {
      res++;
      i += 2;
      continue;
    }
    int breaker = -1;
    for (int k = i + 1; k < n; k++) {
      if (s[k] == ')') {
        res++;
        breaker = k;
        break;
      }
    }
    if (breaker == -1) break;
    i = breaker + 1;
  }
  int remain = 0;
  if (i < n) {
    remain = n - i;
  }

  cout << res << " " << remain << endl;
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