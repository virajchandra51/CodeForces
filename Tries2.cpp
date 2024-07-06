#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int childReferences[26];
    int stringEndingHere;
    Node()
    {
        for (int i = 0; i < 26; i++)
            childReferences[i] = -1;
        stringEndingHere = 0;
    }
    bool canDeleteNode()
    {
        if (stringEndingHere > 0)
            return false;
        for (int i = 0; i < 26; i++)
            if (childReferences[i] != -1)
                return false;
        return true;
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

    void addString(string a)
    {
        int currentNode = root;
        for (auto ch : a)
        {
            int characterIndex = ch - 'a';
            if (nodes[currentNode].childReferences[characterIndex] == -1)
            {
                nodes[currentNode].childReferences[characterIndex] = nodes.size();
                nodes.push_back(Node());
            }
            currentNode = nodes[currentNode].childReferences[characterIndex];
        }
        nodes[currentNode].stringEndingHere++;
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

    bool deleteRecursively(string &a, int currentNode, int index)
    {
        if (index == a.size())
        {
            nodes[currentNode].stringEndingHere--;
            return nodes[currentNode].canDeleteNode();
        }
        int childNode = nodes[currentNode].childReferences[a[index] - 'a'];
        bool childDeleted = deleteRecursively(a, childNode, index + 1);
        if (childDeleted)
            nodes[currentNode].childReferences[a[index] - 'a'] = -1;
        return nodes[currentNode].canDeleteNode();
    }

    void deleteString(string a)
    {
        if(!searchString(a))
            return;
        deleteRecursively(a, root, 0);
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
    cout << newTrie.searchString(x) << endl;
    newTrie.deleteString(x);
    cout << newTrie.searchString(x) << endl;
    newTrie.deleteString(x);
    cout << newTrie.searchString(x) << endl;
    return 0;
}