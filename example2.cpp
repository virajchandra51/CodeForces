const int BITS = 30;
class TrieNode
{
public:
    TrieNode *children[2];
    int numbersGoingBelow;
    TrieNode()
    {
        children[0] = children[1] = NULL;
        numbersGoingBelow = 0;
    }
};

class Solution
{
public:
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
    }

    // how many numbers y give (x ^ y) < k
    int countSmaller(int x, int k)
    {
        TrieNode *node = root;
        int count = 0;
        for (int i = BITS - 1; i >= 0; i--)
        {
            int xb = (x >> i) & 1, kb = (k >> i) & 1;
            if (kb == 1)
            {
                // same-bit child (yb = xb): XOR bit = 0 < 1  -> all of it is < k, count it
                if (node->children[xb])
                    count += node->children[xb]->numbersGoingBelow;
                // opposite child (yb = xb^1): XOR bit = 1 == kb -> walk into it
                if (node->children[xb ^ 1])
                    node = node->children[xb ^ 1];
                else
                    break;
            }
            else
            {
                // opposite child (yb = xb^1): XOR bit = 1 > 0 -> too big, ignore
                // same-bit child (yb = xb):  XOR bit = 0 == kb -> walk into it
                if (node->children[xb])
                    node = node->children[xb];
                else
                    break;
            }
        }
        return count;
    }

    int cntPairs(vector<int> &arr, int k)
    {
        long long ans = 0;
        for (int x : arr)
            insert(x);
        for (int x : arr)
            ans += countSmaller(x, k);
        ans = ans - arr.size(); // remove self-pairs
        ans = ans / 2;          // remove double counting
        return (int)(ans);
    }
};

// Time Complexity = O(N * BITS) = O(N * 30)
// Space Complexity = O(N * 30 * 2)