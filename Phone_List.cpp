#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[10];
    int stringsGoingBelow;
    TrieNode()
    {
        for (int i = 0; i < 10; i++)
            children[i] = NULL;
        stringsGoingBelow = 0;
    }
};

class Trie
{
public:
    TrieNode *root;
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - '0';
            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->stringsGoingBelow++;
        }
    }

    int countWordsWithPrefix(const string &prefix)
    {
        TrieNode *node = root;
        for (char ch : prefix)
        {
            int idx = ch - '0';
            if (node->children[idx] == NULL)
                return 0;
            node = node->children[idx];
        }
        return node->stringsGoingBelow;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Trie trie;
        trie.root = new TrieNode();

        vector<string> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
            trie.insert(nums[i]);
        }

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            // each number inserted once -> >1 string with this prefix means
            // a longer number extends it, so nums[i] is a prefix of another.
            if (trie.countWordsWithPrefix(nums[i]) > 1)
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}

// Time Complexity: O(N * 10)
// Space Complexity: O(N * 10 * 10)