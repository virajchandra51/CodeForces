#include <bits/stdc++.h>
using namespace std;

struct Node
{
    long long val;
    Node()
    {
        val = 0;
    }
    Node(long long p1)
    {
        val = p1;
    }
    void merge(Node &l, Node &r)
    {
        val = gcd(l.val, r.val);
    }
};

struct SegTree
{
    vector<Node> tree;
    vector<long long> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<long long> &a)
    { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) // Never change this
    {
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    Node make_query(int left, int right)
    {
        return query(0, n - 1, 1, left, right);
    }
};

void solve()
{
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        while (q--)
        {
            long long l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
    }
    else
    {
        vector<long long> diff(n - 1);
        for (long long i = 0; i < n - 1; i++)
            diff[i] = abs(a[i + 1] - a[i]);
        struct SegTree tree = SegTree(n - 1, diff);
        // O(n*logn*logn)
        while (q--) // q
        {
            long long l, r;
            cin >> l >> r;
            l--;
            r--;
            long long gcdValue = tree.make_query(l, r - 1).val; // ~ O(logn * log(a[i]))
            if (gcdValue == 0)
                cout << 0 << " ";
            else
                cout << gcdValue << " ";

        } // O(n*logn *logn) ~ O(nlog2n)
        cout << endl;
    }
}

// tc - O(q*logn*logn + n*logn*logn)
// sc - O(n)

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}