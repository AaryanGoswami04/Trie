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

  Trie() { root = new TrieNode('\0'); }
  void insertuntil(TrieNode *root, string word) {
    // base case
    if (word.length() == 0) {
      root->isTerminal = true; // Mark the node as end of the word
      return;
    }
    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL) // Key is present
      child = root->children[index];

    else { // absent
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }
    // recursion
    insertuntil(child, word.substr(1));
  }

  void insertword(string word) { 
    insertuntil(root, word); 
    }

  bool searchuntil(TrieNode *root, string word) {
    // base case
    if (word.length() == 0)
      return root->isTerminal;

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL) // Key is present
      child = root->children[index];

    else { // absent
      return false;
    }
    // recursion
    return searchuntil(child, word.substr(1));
  }

  bool searchword(string word) { 
    return searchuntil(root, word); 
    }
};
int main() {
  Trie t;
  t.insertword("ABCD");
  t.insertword("ABD");
  t.insertword("ABCDF");
  t.insertword("ADG");
  cout<<"sucess"<<endl;
  cout << t.searchword("ABCD") << endl;
}