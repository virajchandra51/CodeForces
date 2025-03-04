class TrieNode
{
public:
    // Initialize your data structure here.
    int strings_ending_here;
    int strings_going_below;
    TrieNode *children[26];
    TrieNode()
    {
        strings_ending_here = 0;
        strings_going_below = 0;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie{
    public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    // add functions
};

// Adds a word into the trie.
void add(string word)
{
    TrieNode *curr = root;
    for (auto ch : word)
    {
        if (curr->children[ch - 'a'] == NULL)
            curr->children[ch - 'a'] = new TrieNode();
        curr = curr->children[ch - 'a'];
        curr->strings_going_below++;
    }
    curr->strings_ending_here++;
}

// Searches a word in the trie.
void search(string word)
{
    TrieNode *curr = root;
    for (auto ch : word)
    {
        if (curr->children[ch - 'a'] == NULL)
            return false;
        curr = curr->children[ch - 'a'];
    }
    curr->strings_ending_here > 0;
}


const int letters = 26;
struct TrieNode
{
    vector<int> children;
    int strings_ending_here;
    int strings_going_below;
    TrieNode()
    {
        children.resize(letters, -1);
        strings_ending_here = 0;
        strings_going_below = 0;
    }
};

struct Trie{
    vector<Node> TrieTree;
    int sizeOfTrie = 0;
    Trie(){
        TrieTree.push_back(Node());
        sizeOfTrie++;
    }
    // add functions
}

void add(string word)
{
    int currNode = 0;
    for(auto ch: word){
        int index = ch-'a';
        if(TrieTree[currNode].children[index] == -1){
            TrieTree[currNode].children[index] = sizeOfTrie;
            TrieTree.push_back(Node());
            sizeOfTrie++;
        }
        currNode = TrieTree[currNode].children[index];
        TrieTree[currNode].strings_going_below++;
    }
    TrieTree[currNode].strings_ending_here++;
}

bool search(string word)
{
    int currNode = 0;
    for(auto ch: word){
        int index = ch-'a';
        if(TrieTree[currNode].children[index] == -1)
            return false;
        currNode = TrieTree[currNode].children[index];
    }
    return TrieTree[currNode].strings_ending_here > 0;
}

void delete(string word)
{
    if(search(word) == false)
        return;
    int currNode = 0;
    for(auto ch: word){
        int index = ch-'a';
        int child = TrieTree[currNode].children[index];
        TrieTree[child].strings_going_below--;
        if(TrieTree[child].strings_going_below == 0)
            TrieTree[currNode].children[index] = -1;
        currNode = child;
    }
    TrieTree[currNode].strings_ending_here--;
}