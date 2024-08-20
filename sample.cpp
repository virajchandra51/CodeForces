#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds; 

#define endl '\n' 
#define int long long 
const int inf = 1e18; 

const int MAX_NODES = 5e5 + 5; 
const int MAX_LOG = 20; 

int num_nodes, num_queries; 
int parent[MAX_LOG][MAX_NODES]; 
int node_values[MAX_NODES]; 
pair<int, int> segment_tree[20]; 

void build_segment_tree(int left, int right, int node_index) 
{ 
    if (left == right) 
    { 
        segment_tree[node_index] = {node_values[left], left}; 
        return; 
    } 
    int mid = (left + right) >> 1; 
    build_segment_tree(left, mid, 2 * node_index); 
    build_segment_tree(mid + 1, right, 2 * node_index + 1); 
    segment_tree[node_index] = max(segment_tree[2 * node_index], segment_tree[2 * node_index + 1]); 
} 

pair<int, int> query_segment_tree(int left, int right, int node_index, int query_left, int query_right) 
{ 
    if (left > query_right || right < query_left) return {-inf, -1}; 
    if (left >= query_left && right <= query_right) return segment_tree[node_index]; 
    int mid = (left + right) >> 1; 
    return max(query_segment_tree(left, mid, 2 * node_index, query_left, query_right), 
               query_segment_tree(mid + 1, right, 2 * node_index + 1, query_left, query_right)); 
} 

void solve() 
{ 
    cin >> num_nodes >> num_queries; 
    for (int i = 1; i <= num_nodes; i++)  
    { 
        cin >> node_values[i]; 
        node_values[i] += i; 
    } 
    build_segment_tree(1, num_nodes, 1);
    for(auto it:segment_tree) cout<<it.first<<" "<<it.second<<endl;
    for (int i = 1; i <= num_nodes; i++) 
    { 
        parent[0][i] = query_segment_tree(1, num_nodes, 1, i, node_values[i]).second; 
    } 
    for (int i = 1; i < MAX_LOG; i++)  
    { 
        for (int j = 1; j <= num_nodes; j++) 
        { 
            parent[i][j] = parent[i - 1][parent[i - 1][j]]; 
        } 
    } 

    while (num_queries--) 
    { 
        int start_node, target_value; 
        cin >> start_node >> target_value; 
        if (node_values[start_node] >= target_value) 
        { 
            cout << 1 << '\n'; 
            continue; 
        } 

        int result = 0; 
        for (int i = MAX_LOG - 1; i >= 0; i--) 
        { 
            if (node_values[parent[i][start_node]] >= target_value) continue; 
            start_node = parent[i][start_node]; 
            result += (1LL << i); 
        } 
        if (node_values[parent[0][start_node]] < target_value) 
        { 
            cout << -1 << endl; 
            continue; 
        } 
        cout << result + 2 << endl; 
    } 
} 

int32_t main()  
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int num_test_cases; 
    cin >> num_test_cases; 
    while (num_test_cases--) 
    { 
        solve(); 
    } 

    return 0; 
}