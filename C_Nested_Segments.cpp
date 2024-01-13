#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree
{
public:
    class Node
    {
    public:
        Node *left;
        Node *right;
        ll startInterval;
        ll endInterval;
        ll data;
        Node(ll startInterval, ll endInterval)
        {
            this->startInterval = startInterval;
            this->endInterval = endInterval;
        }
    };
    Node *root;
    SegmentTree(vector<ll> &arr)
    {
        this->root = constructTree(arr, 0, arr.size() - 1);
    }
    Node *constructTree(vector<ll> &arr, ll start, ll end)
    {
        if (start == end)
        {
            Node *leaf = new Node(start, end);
            leaf->data = arr[start];
            return leaf;
        }
        Node *n = new Node(start, end);
        ll mid = (start + end) / 2;
        n->left = constructTree(arr, start, mid);
        n->right = constructTree(arr, mid + 1, end);
        n->data = n->left->data + n->right->data;
        return n;
    }
    ll query(ll qL, ll qR, Node *node)
    {
        if (node->startInterval >= qL && node->endInterval <= qR)
        {
            return node->data;
        } // node intervals totally inside query
        else if (node->startInterval > qR || node->endInterval < qL)
            return 0; // node intervals totally outside query
        else
            return query(qL, qR, node->left) + query(qL, qR, node->right);
    }
    ll update(ll index, ll value, Node *node)
    {
        if (index >= node->startInterval && index <= node->endInterval)
        {
            if (index == node->startInterval && index == node->endInterval)
            {
                node->data = value;
                return node->data;
            }
            else
            {
                node->data = update(index, value, node->left) + update(index, value, node->right);
                return node->data;
            }
        }
        return node->data;
    }
    void display(Node *node)
    {
        string s = "";
        if (node->left)
        {
            s = s + "Interval=[" + to_string(node->left->startInterval) + "-" + to_string(node->left->endInterval) + "] and Data: " + to_string(node->left->data) + " => ";
        }
        else
            s += "No left child found";
        // current node
        s = s + "Interval=[" + to_string(node->startInterval) + "-" + to_string(node->endInterval) + "] and Data: " + to_string(node->data) + " <= ";
        if (node->right)
        {
            s = s + "Interval=[" + to_string(node->right->startInterval) + "-" + to_string(node->right->endInterval) + "] and Data: " + to_string(node->right->data);
        }
        else
            s += "No right child found";

        cout << s << endl;

        if (node->left)
            display(node->left);
        if (node->right)
            display(node->right);
    }
};

int main()
{
    long long n;
    cin >> n;
    n *= 2;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // taking input

    vector<long long> a(n, 0);
    // array represents our segment tree array of length n , each value 0

    SegmentTree *tree = new SegmentTree(a);
    // segment tree creation

    vector<pair<long long, long long> > indexes(n, {-1, -1});


    for (int i = 0; i < n; i++)
    {
        if (indexes[v[i] - 1].first == -1)
            indexes[v[i] - 1].first = i;
        else
            indexes[v[i] - 1].second = i;
    }

    set<long long> s; // set to store for check of duplicate values
    vector<long long> answer(n/2, 0);

    for (int i = 0; i < n; i++)
    {
        if (s.find(v[i]) != s.end())
        {
            answer[v[i] - 1] = tree->query(indexes[v[i] - 1].first, indexes[v[i] - 1].second, tree->root);
            // calculating the sum of the array for the segment l to r of the value v[i]

            tree->update(indexes[v[i] - 1].first, 1, tree->root);
            // updating the left end of the segment of value v[i] as 1
            
        }
        s.insert(v[i]);
    }

    for (auto it : answer)
        cout << it << " ";
    cout << endl;

    return 0;
}