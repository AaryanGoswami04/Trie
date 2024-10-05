/*Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.
2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.
3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.
4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.

Note:
1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.
2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.*/
#include <bits/stdc++.h> 
class Node{
    public:
        int endOfWord;
        int startOfWord;
        char data;
        Node* children[26];
       
        Node(char ch){
            endOfWord = 0;
            startOfWord = 0;
            data = ch;
            for(int i=0; i<26; i++) children[i] = NULL;
        }
};
class Trie{
    public:
  
    Node* root;

    Trie() {
        
        Node* r = new Node('\0');
        root = r;
    }

    void insert(string &word){
        Node* curr = root;
        
        int n = word.size();
      
        for(int i=0; i<n; i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL)
            {
                Node* newNode = new Node('a' + idx);
                curr->children[idx] = newNode;
            }
            
            curr = curr->children[idx];
            curr->startOfWord++;
        }
        (curr->endOfWord)++;
    }

    int countWordsEqualTo(string &word){
        Node* curr = root;
        
        int n = word.size();
      
        for(int i=0; i<n; i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL) return 0;

            curr = curr->children[idx];
        }

        return curr->endOfWord;
    }
   
    int countWordsStartingWith(string &word){
        Node* curr = root;
        
        int n = word.size();
      
        for(int i=0; i<n; i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL) return 0;

            curr = curr->children[idx];
        }
        return curr->startOfWord;
    }
    void searchUntil(int i, Node*& root, string word){
        if (i == word.size()-1) {
            root->startOfWord--;
            root->endOfWord--;

            if (root->startOfWord == 0) {
                delete (root);
                root = nullptr;
            }
            return;
        }
        searchUntil(i+1, root->children[word[i+1] - 'a'],word);

        root->startOfWord--;
     
        if(root->startOfWord == 0){
            delete(root);
            root = nullptr;
        }
    }
    void erase(string &word){
        Node* curr = root;

        searchUntil(0, root->children[word[0] - 'a'],word);
    }
};
