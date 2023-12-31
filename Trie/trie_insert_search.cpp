// Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

// Example 1:

// Input:
// N = 8
// key[] = {the,a,there,answer,any,by,
//          bye,their}
// search = the
// Output: 1
// Explanation: the is present in the given
// string "the a there answer any by bye
// their"

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++)
        {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++)
            insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends

// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

// Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    TrieNode *node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = CHAR_TO_INDEX(key[i]);
        if (!node->children[index])
        {
            // if not present create a  new node
            node->children[index] = getNode();
        }
        node = node->children[index];
    }
    node->isLeaf = true;
}

// Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key)
{
    // code here
    TrieNode *node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = CHAR_TO_INDEX(key[i]);
        if (!node->children[index])
        {
            // not found case
            return false;
        }
        node = node->children[index];
    }
    return (node->isLeaf && node != nullptr);
}