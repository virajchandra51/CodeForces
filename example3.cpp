#include <bits/stdc++.h>
using namespace std;

const int BITS = 30;
class TrieNode
{
public:
    TrieNode *children[2];
    bool isEndOfNumber;
    int numbersGoingBelow;
    TrieNode()
    {
        children[0] = children[1] = NULL;
        isEndOfNumber = false;
        numbersGoingBelow = 0;
    }
};

TrieNode *root = new TrieNode();

void insert(int x)
{
    TrieNode *node = root;
    for (int i = BITS - 1; i >= 0; i--)
    {
        int bit = (x >> i) & 1;
        if (!node->children[bit])
            node->children[bit] = new TrieNode();
        node = node->children[bit];
        node->numbersGoingBelow++;
    }
    node->isEndOfNumber = true;
}

// how many already-stored numbers y give (x ^ y) < k
int countSmaller(int x, int k)
{
    TrieNode *node = root;
    int res = 0;
    for (int i = BITS - 1; i >= 0 && node; i--)
    {
        int xb = (x >> i) & 1, kb = (k >> i) & 1;
        if (kb)
        {
            if (node->children[xb])
                res += node->children[xb]->numbersGoingBelow; // XOR bit 0 => surely < k
            node = node->children[xb ^ 1];                    // XOR bit 1 ties k, go deeper
        }
        else
        {
            node = node->children[xb]; // only XOR bit 0 stays < k
        }
    }
    return res;
}

long long countPairs(vector<int> &arr, int k)
{ // <- the function you submit
    root = new TrieNode();
    long long ans = 0;
    for (int x : arr)
    {
        ans += countSmaller(x, k);
        insert(x);
    } // query, then insert
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 5};
    cout << countPairs(a, 5) << " (expect 4)\n";
    srand(7);
    for (int t = 0; t < 5; t++)
    {
        int n = rand() % 40 + 2, k = rand() % 200;
        vector<int> v(n);
        for (int &x : v)
            x = rand() % 256;
        long long bf = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((v[i] ^ v[j]) < k)
                    bf++;
        cout << (bf == countPairs(v, k) ? "ok" : "MISMATCH") << " " << countPairs(v, k) << " vs " << bf << "\n";
    }
}