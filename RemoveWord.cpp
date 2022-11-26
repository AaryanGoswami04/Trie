#include <iostream>
using namespace std;
//Time complexity: O(word.size())
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

  Trie() { 
    root = new TrieNode('\0');
  }

  void Removeuntil(TrieNode *root, string word) {
    // base case
    if (word.length() == 0) {
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
      child = root->children[index];
    else {
      cout << "No such word exists" << endl;
      return;
    }
    // recursion
    Removeuntil(child, word.substr(1));
  }
  
  void Removeword(string word) { 
    Removeuntil(root, word);
  }
};
int main() {
  Trie t;
  t.insertword("ABCD");
  t.insertword("ABD");
  t.insertword("ABCDF");
  t.insertword("ADG");
  cout << t.searchword("ABCD") << endl;
  t.Removeword("ADGE");
  cout << t.searchword("ADGE") << endl;
}
