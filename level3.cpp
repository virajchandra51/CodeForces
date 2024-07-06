#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int childReference[26];
    int stringEndingHere;
    int stringEndingBelow;
    Node()
    {
        stringEndingHere = 0;
        stringEndingBelow = 0;
        for (int i = 0; i < 26; i++)
        {
            childReference[i] = -1;
        }
    }
};

struct Trie
{
    int root;
    vector<Node> nodes;
    Trie()
    {
        root = 0;
        nodes.push_back(Node());
    }

    void precomputeSpecialStringBelow(int currentNode)
    {
        nodes[currentNode].stringEndingBelow = nodes[currentNode].stringEndingHere;
        for (int i = 0; i < 26; i++)
        {
            if (nodes[currentNode].childReference[i] != -1)
            {
                nodes[currentNode].stringEndingBelow += nodes[nodes[currentNode].childReference[i]].stringEndingBelow;
            }
        }
    }

    void addRecursively(string a, int currentNode, int index)
    {
        if (index == a.size())
        {
            nodes[currentNode].stringEndingHere++;
            precomputeSpecialStringBelow(currentNode);
            return;
        }
        int childNode = nodes[currentNode].childReference[a[index] - 'a'];
        if (childNode == -1)
        {
            nodes[currentNode].childReference[a[index] - 'a'] = nodes.size();
            nodes.push_back(Node());
            childNode = nodes[currentNode].childReference[a[index] - 'a'];
        }
        addRecursively(a, childNode, index + 1);
        precomputeSpecialStringBelow(currentNode);
    }

    void addString(string a)
    {
        addRecursively(a, root, 0); // (string, currentNode, index)
    }

    bool searchString(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReference[characterIndex] == -1)
                return false;
            currentNode = nodes[currentNode].childReference[characterIndex];
        }
        return nodes[currentNode].stringEndingHere > 0;
    }

    int commonPrefixes(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReference[characterIndex] == -1)
                return 0;
            currentNode = nodes[currentNode].childReference[characterIndex];
        }
        return nodes[currentNode].stringEndingBelow;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto &a : words)
    {
        cin >> a;
    }
    Trie trie = Trie();
    for (auto a : words)
    {
        trie.addString(a);
    }
    string x;
    cin >> x;
    cout << trie.commonPrefixes(x);
    return 0;
}