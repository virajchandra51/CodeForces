#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        inDegree[a]++;
        inDegree[b]++;
    }
    int countOfTwo = 0; // count of Nodes with inDegree 2
    int countOfOne = 0;// count of Nodes with inDegree 1
    int countOfGreaterThanTwo = 0; // count of Nodes with inDegree greater than 2
    for (int node = 1; node <= n; node++)
    {
        if (inDegree[node] == 1)
            countOfOne++;
        if (inDegree[node] == 2)
            countOfTwo++;
        if (inDegree[node] > 2)
            countOfGreaterThanTwo++;
    }
    if (countOfOne == 2 && countOfTwo == (n - 2))
    // means a tree is skewed or in straight line
    {
        cout << "Yes" << endl;
        cout << 1 << endl;
        for (int node = 1; node <= n; node++)
        {
            if (inDegree[node] == 1)
            // print those nodes with indegree one since they will act as ends
            // of the single path in tree
                cout << node << " ";
        }
        cout << endl;
    }
    else if (countOfGreaterThanTwo == 1)
    {
        cout << "Yes" << endl;
        int nodeValue = -1; // finding the node value with is the main intersection for all
        for(int node=1;node<=n;node++)
        {
            if(inDegree[node]>2)
            {
                nodeValue = node;
                cout<<inDegree[node]<<endl;
                break;
            }
        } // printing the path count as it's indegree count and storing that node value too
        for(int node=1;node<=n;node++)
        {
            if(inDegree[node]==1)
            // print all node along with that node value as two ends of path
            {
                cout<<nodeValue<<" "<<node<<endl;
            }
        }
    }
    // this means the tree has two or more vertexes with indegree greater than 2
    // so no decomposition can be done in the conditions
    else cout<<"No"<<endl;
    return 0;
}

// TC - O(n)
// SC - O(n)