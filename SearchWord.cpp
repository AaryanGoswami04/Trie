#include <iostream>
using namespace std;
class TrieNode {
public:
  char data;
  TrieNode *children[26]; // array of pointers to next level trie nodes
  bool isTerminal;        // To mark end of word node
  TrieNode(char ch) {
    data = ch;
    for (int i = 0; i < 26; i++)
      children[i] = NULL;
    isTerminal = false;
  }
};
class Trie {
public:
  TrieNode *root;

  bool Searchuntil(TrieNode *root, string word) {
    // base case
    if (word.length() == 0)
      return root->isTerminal;

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL) // Key is present
      child = root->children[index];

    else {       // absent
      return false;
    }
    // recursion
    return Searchuntil(child, word.substr(1));
  }

  bool Searchword(string word) { 
    return Searchuntil(root, word); 
    }
};
int main() {
  Trie t;
  cout << t.Searchword("ABCD") << endl;
}
