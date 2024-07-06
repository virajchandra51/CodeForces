#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int childReferences[26];
    int stringEndingHere;
    int stringsEndingBelow;
    Node()
    {
        for (int i = 0; i < 26; i++)
            childReferences[i] = -1;
        stringEndingHere = 0;
        stringsEndingBelow = 0;
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

    void precomputeSpecialStringsBelow(int currentNode)
    {
        nodes[currentNode].stringsEndingBelow = nodes[currentNode].stringEndingHere;
        for (int i = 0; i < 26; i++)
        {
            if (nodes[currentNode].childReferences[i] != -1)
                nodes[currentNode].stringsEndingBelow += nodes[nodes[currentNode].childReferences[i]].stringsEndingBelow;
        }
    }

    void addRecursively(string &a, int currentNode, int index)
    {
        if (index == a.size())
        {
            nodes[currentNode].stringEndingHere++;
            precomputeSpecialStringsBelow(currentNode);
            return;
        }
        int child = nodes[currentNode].childReferences[a[index] - 'a'];
        if (child == -1)
        {
            nodes[currentNode].childReferences[a[index] - 'a'] = nodes.size();
            nodes.push_back(Node());
            child = nodes[currentNode].childReferences[a[index] - 'a'];
        }
        addRecursively(a, child, index + 1);
        precomputeSpecialStringsBelow(currentNode);
    }

    void addString(string a)
    {
        addRecursively(a, root, 0);
    }

    bool searchString(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReferences[characterIndex] == -1)
                return false;
            currentNode = nodes[currentNode].childReferences[characterIndex];
        }
        return nodes[currentNode].stringEndingHere > 0;
    }

    int commonPrefixes(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReferences[characterIndex] == -1)
                return 0;
            currentNode = nodes[currentNode].childReferences[characterIndex];
        }
        return nodes[currentNode].stringsEndingBelow;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    Trie newTrie = Trie();
    for (auto word : words)
        newTrie.addString(word);

    string x;
    cin >> x;
    cout << newTrie.commonPrefixes(x) << endl;
    return 0;
}