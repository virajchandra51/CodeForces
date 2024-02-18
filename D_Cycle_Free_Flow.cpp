#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    vector<Node *> lift;
    vector<int> minLift;
    int depth, id;
    vector<Node *> adj;
    vector<int> edges;

    Node(int id) : id(id), depth(0)
    {
        lift.resize(20, nullptr);
        minLift.resize(20, 0);
    }

    void dfs0(Node *par, int parEdge, int depth)
    {
        this->depth = depth;
        lift[0] = par;
        minLift[0] = parEdge;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[i] == par)
                continue;
            adj[i]->dfs0(this, edges[i], depth + 1);
        }
    }

    Node *goUp(int nSteps)
    {
        if (nSteps == 0)
            return this;
        int exp = __builtin_ctz(nSteps);
        return lift[exp]->goUp(nSteps - (1 << exp));
    }

    Node *lca(Node *o, int nJumps)
    {
        if (this == o)
            return this;
        if (depth != o->depth)
        {
            if (depth > o->depth)
                return goUp(depth - o->depth)->lca(o, 19);
            return lca(o->goUp(o->depth - depth), 19);
        }
        if (lift[0] == o->lift[0])
            return lift[0];
        while (lift[nJumps] == o->lift[nJumps])
            nJumps--;
        return lift[nJumps]->lca(o->lift[nJumps], nJumps);
    }

    int goUpMin(int nSteps)
    {
        if (nSteps == 0)
            return INT_MAX;
        int minExp = (1 << (__builtin_ffs(nSteps)-1));
        int exp = __builtin_ctz(minExp);
        return min(minLift[exp], lift[exp]->goUpMin(nSteps - minExp));
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Node *> nodes(n + 1);
    for (int i = 0; i <= n; i++)
        nodes[i] = new Node(i + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a - 1]->adj.push_back(nodes[b - 1]);
        nodes[b - 1]->adj.push_back(nodes[a - 1]);
        nodes[a - 1]->edges.push_back(c);
        nodes[b - 1]->edges.push_back(c);
    }
    nodes[0]->dfs0(nullptr, -1, 0);
    int level = ceil(log2(n));
    for (int e = 1; e < level; e++)
    {
        for (auto nn : nodes)
        {
            if (nn->lift[e - 1] != nullptr)
            {
                nn->lift[e] = nn->lift[e - 1]->lift[e - 1];
                nn->minLift[e] = min(nn->minLift[e - 1], nn->lift[e - 1]->minLift[e - 1]);
            }
        }
    }
    int q;
    cin >> q;
    for (int qq = 0; qq < q; qq++)
    {
        int aa, bb;
        cin >> aa >> bb;
        Node *a = nodes[aa - 1];
        Node *b = nodes[bb - 1];
        Node *lca = a->lca(b, level);
        int min_val = min(a->goUpMin(a->depth - lca->depth), b->goUpMin(b->depth - lca->depth));
        cout << min_val << endl;
    }
    return 0;
}
