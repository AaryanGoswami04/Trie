/*Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, ‘A’ of size ‘N’. Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".

Example :
N = 4
A = [ “ab” , “abc” , “a” , “bp” ] 

Explanation : 

Only prefix of the string “a” is “a” which is present in array ‘A’. So, it is one of the possible strings.
Prefixes of the string “ab” are “a” and “ab” both of which are present in array ‘A’. So, it is one of the possible strings.
Prefixes of the string “bp” are “b” and “bp”. “b” is not present in array ‘A’. So, it cannot be a valid string.
Prefixes of the string “abc” are “a”,“ab” and “abc” all of which are present in array ‘A’. So, it is one of the possible strings.

We need to find the maximum length string, so “abc” is the required string.*/
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
            if (curr->children[idx] == NULL) {
              Node *newNode = new Node('a' + idx);
              curr->children[idx] = newNode;
            }

            curr = curr->children[idx];
            curr->startOfWord++;
        }
        
        (curr->endOfWord)++;
    }

    //Find the longest path, for which every node's endOfWord > 0
    void dfs(Node *root, string temp, string& ans){
        if((root == NULL) or (root->endOfWord == 0 and root->data != '\0')){
            if((temp.size() > ans.size()) or (temp.size() == ans.size() and ans > temp)) {
                ans = temp;
            }
            return;
        }

        if(root->data != '\0') temp.push_back(root->data);

        for(int i=0; i<26; i++){
            dfs(root->children[i], temp, ans);
        }
    }
    string lcs(){
        string ans, temp;
        dfs(root, temp, ans);

        return ans;
    }
};

string completeString(int n, vector<string> &a) {
    Trie obj;
    for(auto s:a) obj.insert(s);

    string res = obj.lcs();
    return res == "" ? "None" : res;
}
