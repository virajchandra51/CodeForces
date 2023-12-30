#include <bits/stdc++.h>

    //Whatever
    //IMSS I am sad scam 

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
#define ioset ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
#define vi vector<long long>
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

long long dfs1(long long node, vector<vi> &tree, vi &cntact, vi&mx, vi&act, map<long long,long long> &m){
    mx[node] = cntact[node];
    for(auto it: tree[node]){
        mx[node] = max(mx[node], dfs1(it, tree, cntact, mx, act, m));
    }
    return mx[node];
}
void dfs2(long long node, vector<vi> &tree, vi &cntact, vi&mx, vi&act, map<long long,long long> &m){
    for(auto it: tree[node]){
        m[act[it]]++;
        if (m[act[it]]==1) cntact[it] = cntact[node]+1;
        else cntact[it] = cntact[node];
        dfs2(it, tree, cntact, mx, act, m);
        m[act[it]]--;
    }
}


void solve()
{
    long long n; cin>>n;
    vector<vi> tree(n+1);
    vector<long long> act(n+1, 0);
    for(long long i=2; i<=n; i++){
        long long k; cin>>k;
        tree[k].pb(i);
    }
    for(long long i=1; i<=n; i++){
        cin>>act[i];
    }
    vi cntact(n+1, 0), mx(n+1, 1);
    map<long long,long long> m;
    cntact[1] = 1;
    m[act[1]]++;
    dfs2(1, tree, cntact, mx, act, m);
    dfs1(1, tree, cntact, mx, act, m);
    // rep(i,n+1) cout<<mx[i]<<" ";
    // cout<<endl;
    // rep(i,n+1) cout<<cntact[i]<<" ";
    // cout<<endl;
    ll ans = 1;
    for(long long i=1; i<=n; i++){
        long long m1 = 1;
        for(auto it: tree[i]){
            // cout<<cntact[i]<<" "<<mx[it]<<endl;
            ans = max(ans, 1ll * (-cntact[i]+mx[it]+1) * m1);
            m1 = max(m1, -cntact[i]+mx[it]+1);
        }
    }
    cout<<ans<<endl;
}


int32_t main()
{
    ioset
    long long t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}