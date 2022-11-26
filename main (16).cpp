#include <iostream>
using namespace std;
class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
      data=ch;
      for(int i=0; i<26; i++)
        children[i]=NULL;
      isTerminal=false;
    }
};
class Trie{
  public:
    TrieNode* root;
    Trie(){
      root=new TrieNode('\0');     
    }
    void insertuntil(TrieNode* root, string word){
      //base case
      if(word.length()==0){
        root->isTerminal=true;
        return;
      }
      int index = word[0]-'A';
      TrieNode* child;
      
      if(root->children[index]!=NULL)
        child=root->children[index];
        
      else{  //absent
        child=new TrieNode(word[0]);
        root->children[index]=child;
      }
      //recursion
      insertuntil(child, word.substr(1));
    }
    void insertword(string word){
      insertuntil(root, word);
    }
};
int main() {
  Trie *t=new Trie();
  t->insertword("ABCD");
  cout<<"success"<<endl;
}