#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // Read the ranges [l_i, r_i] for each node
        vector<pair<int, int>> ranges(n);
        for (int i = 0; i < n; ++i) {
            cin >> ranges[i].first >> ranges[i].second;
        }

        // Build the tree using adjacency lists
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v; // Convert to 0-based indexing
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find the maximum r_i across all nodes
        int max_r = 0;
        for (int i = 0; i < n; ++i) {
            if (ranges[i].second > max_r) {
                max_r = ranges[i].second;
            }
        }

        // Output the result for this test case
        cout << max_r << '\n';
    }

    return 0;
}