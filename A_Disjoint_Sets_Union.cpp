#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
	int n;
	vector<int> rank;
	vector<int> parent;
	// store other info as required
	UnionFind(int n) {
		rank.resize(n);
		fill(rank.begin(), rank.end(), 0);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] == rank[b]) {
			rank[a]++;
		}
		if (rank[a] > rank[b]) {
			parent[b] = a;
		} else {
			parent[a] = b;
		}
	}
};

int32_t main()
{
    long long n, q;
    cin >> n >> q;
    UnionFind dsu(n + 1);
    for (int i = 0; i < q; i++)
    {
        string o;
        long long u, v;
        cin >> o >> u >> v;
        if (o[0] == 'u')
        {
            dsu.merge(u, v);
        }
        else
        {
            if (dsu.get(u) == dsu.get(v))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}