#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
public:
    vector<int> par, size;

    DSU(int n = 0)
    {
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findLeader(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findLeader(par[node]); // path comp
    }

    void unionbySize(int u, int v)
    {
        int UparU = findLeader(u);
        int UparV = findLeader(v);
        if (UparU == UparV)
            return;
        if (size[UparU] < size[UparV])
        {
            par[UparU] = UparV;
            size[UparV] += size[UparU];
        }
        else
        {
            par[UparV] = UparU;
            size[UparU] += size[UparV];
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<char> > a(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j] = s[j];
        }

        DSU dsu(n * m); // O(n * m)

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                {
                    if (i > 0 && a[i - 1][j] == '#')
                        dsu.unionbySize(i * m + j, (i - 1) * m + j);
                    if (j > 0 && a[i][j - 1] == '#')
                        dsu.unionbySize(i * m + j, i * m + j - 1);
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            long long c = 0;
            set<long long> st; // storing leaders
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '#')
                    st.insert(dsu.findLeader(i * m + j));
                else
                {
                    c++;
                    if (i + 1 < n && a[i + 1][j] == '#')
                        st.insert(dsu.findLeader((i + 1) * m + j));
                    if (i - 1 >= 0 && a[i - 1][j] == '#')
                        st.insert(dsu.findLeader((i - 1) * m + j));
                }
            }
            for (auto it : st)
                c += dsu.size[it];
            ans = max(ans, c);
        }

        for (int j = 0; j < m; j++)
        {
            long long c = 0;
            set<long long> st;
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == '#')
                    st.insert(dsu.findLeader(i * m + j));
                else
                {
                    c++;
                    if (j + 1 < m && a[i][j + 1] == '#')
                        st.insert(dsu.findLeader(i * m + j + 1));
                    if (j - 1 >= 0 && a[i][j - 1] == '#')
                        st.insert(dsu.findLeader(i * m + j - 1));
                }
            }
            for (auto it : st)
                c += dsu.size[it];
            ans = max(ans, c);
        }

        cout << ans << endl;
    }
    return 0;
}

// TC - O(n * m * log(n * m))
// SC - O(n * m)