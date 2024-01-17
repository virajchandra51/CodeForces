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
        ll index;
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
            leaf->index = start;
            return leaf;
        }
        Node *n = new Node(start, end);
        ll mid = (start + end) / 2;
        n->left = constructTree(arr, start, mid);
        n->right = constructTree(arr, mid + 1, end);
        if (n->left->data > n->right->data)
        {
            n->data = n->left->data;
            n->index = n->left->index;
        }
        else
        {
            n->data = n->right->data;
            n->index = n->right->index;
        }
        return n;
    }
    ll query(ll value, Node *node)
    {
        if (node->startInterval == node->endInterval)
        {
            return node->index;
        }
        else if (node->left->data >= value)
            return query(value, node->left);
        else
            return query(value, node->right);
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
                node->data = max(update(index, value, node->left), update(index, value, node->right));
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
        s = s + "Interval=[" + to_string(node->startInterval) + "-" + to_string(node->endInterval) + "] and Data: " + to_string(node->data) + " and Index: " + to_string(node->index) + " <= ";
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
    long long n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // taking input

    SegmentTree *tree = new SegmentTree(arr);
    // creating segment tree from the array

    for (int i = 0; i < q; i++)
    {
        long long touristCount;
        cin >> touristCount;
        // taking the group count of tourist input

        if (touristCount > tree->root->data) // case when no value exists where arr[i]>=touristCount
            cout << 0 << " ";
        else
        {
            long long ind = tree->query(touristCount, tree->root);
            // finding the lowest index for which arr[i]>=touristCount

            cout << ind + 1 << " ";
            // printing ind+1 (1-based)

            int newValue = arr[ind] - touristCount;
            arr[ind] = newValue;
            tree->update(ind, newValue, tree->root);
            // updating the tree value as well as array to maintain new hotel capacity

        }
    }
    return 0;
}

// time complexity - O(q * log2(n))
// space complexity - O(n) for sgt