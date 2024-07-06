#include <bits/stdc++.h>

using namespace std;

struct Node
{
    bool specialNode;
    map<char, Node *> children;
    int count = 0;

    Node()
    {
    }

    bool isSpecial()
    {
        return specialNode;
    }

    void markSpecial()
    {
        specialNode = true;
    }

    void markUnspecial()
    {
        specialNode = false;
    }

    Node *goToChild(char ch)
    {
        if (children.find(ch) == children.end())
            return NULL;
        return children[ch];
    }

    void addChild(char ch)
    {
        if (children.find(ch) == children.end())
            children[ch] = new Node();
    }

    bool canDeleteNode()
    {
        if (!specialNode && children.size() == 0)
            return true;
        else
            return false;
    }

    bool containsChild(char ch)
    {
        if (children.find(ch) != children.end())
            return true;
        else
            return false;
    }

    void incrementCount()
    {
        count++;
    }
};

struct Trie
{
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void addString(string a)
    {
        Node *currentNode = root;
        for (auto ch : a)
        {
            if (!currentNode->containsChild(ch))
                currentNode->addChild(ch);
            currentNode = currentNode->goToChild(ch);
            currentNode->incrementCount();
        }
        currentNode->markSpecial();
    }
    bool searchString(string a)
    {
        Node *currentNode = root;
        for (auto ch : a)
        {
            if (!currentNode->containsChild(ch))
                return false;
            currentNode = currentNode->goToChild(ch);
        }
        return currentNode->isSpecial();
    }
    bool deleteRecursively(string a, Node *currentNode, int index)
    {
        if (index == a.size())
        {
            currentNode->markUnspecial();
            return currentNode->canDeleteNode();
        }
        bool childDeleted = deleteRecursively(a, currentNode->goToChild(a[index]), index + 1);
        if (childDeleted)
        {
            currentNode->children.erase(a[index]);
        }
        return currentNode->canDeleteNode();
    }
    void deleteString(string a)
    {
        if (!searchString(a))
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
    return 0;
}