#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll* fact) {ll val1 = fact[n]; ll val2 = mminvprime(fact[r], m); ll val3 = mminvprime(fact[n - r], m); return ((val1 * val2) % m * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}


void dfs(int root, vector<pair<int, int> > *edges, int parent1, int *level, int **parent, int **minimum)
{
    for (auto i : edges[root])
    {
        if (i.first != parent1)
        {
            parent[i.first][0] = root;
            minimum[i.first][0] = i.second;
            level[i.first] = level[root] + 1;
            dfs(i.first, edges, root, level, parent, minimum);
        }
    }
}
int find_lca(int a, int b, int *level, int limit, int **parent)
{
    if (level[a] > level[b])
        swap(a, b);
    int d = level[b] - level[a];
    while (d > 0)
    {
        int x = log2(d);
        b = parent[b][x];
        d -= (1 << x);
    }
    if (a == b)
        return a;
    for (int i = limit - 1; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}
int find_minimum(int a, int **parent, int **minimum, int d)
{
    int ans = INT_MAX;
    while (d > 0)
    {
        int x = log2(d);
        ans = min(ans, minimum[a][x]);
        a = parent[a][x];
        d -= (1 << x);
    }
    return ans;
}

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > *edges = new vector<pair<int, int> >[n];
    for (int i = 0; i < m; i++) //m 
    {
        int a, b;
        int weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        edges[a].push_back({b, weight});
        edges[b].push_back({a, weight});
    }
    int *level = new int[n]();
    int limit = log2(n) + 2;
    int **parent = new int *[n];
    int **minimum = new int *[n];
    for (int i = 0; i < n; i++) // n
    {
        parent[i] = new int[limit];
        minimum[i] = new int[limit];
        for (int j = 0; j < limit; j++) // logn
        {
            minimum[i][j] = INT_MAX;
            parent[i][j] = -1;
        }
    } // nlogn
    dfs(0, edges, -1, level, parent, minimum); //n+m
    for (int j = 1; j < limit; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                int x = parent[i][j - 1];
                parent[i][j] = parent[x][j - 1];
                minimum[i][j] = min(minimum[i][j - 1], minimum[x][j - 1]);
            }
        }
    } // nlogn
    int q;
    cin >> q;
    while (q--) // q
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int x = find_lca(a, b, level, limit, parent); // logn
        int d1 = level[a] - level[x];
        int d2 = level[b] - level[x];
        int min1 = find_minimum(a, parent, minimum, d1); //logn
        int min2 = find_minimum(b, parent, minimum, d2); //logn
        cout << min(min1, min2) << endl;
    } // qlogn
    return 0;
    // tc - O(m + nlogn + qlogn)
    // sc - O(nlogn)
}