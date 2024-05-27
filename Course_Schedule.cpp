#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& graph, vector<int>& inDegree) {
    vector<int> result;
    queue<int> q;

    // Enqueue all nodes with in-degree 0
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    } // n

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        // Reduce in-degree of adjacent nodes
        for (int neighbor : graph[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    } // n+m

    // Check if there is a cycle
    if (result.size() != n) {
        result.clear(); // Clear the result vector
    }

    return result;
} // n+m

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> inDegree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    } // m

    vector<int> sorted = topologicalSort(n, graph, inDegree);

    if (sorted.empty()) {
        cout << "IMPOSSIBLE";
    } else {
        for (int node : sorted) {
            cout << node << " ";
        }
    }

    return 0;
}

// tc - O(n+m) ~ 10^5
// sc - O(n) ~ 10^5