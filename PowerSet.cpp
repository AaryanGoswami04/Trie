/* Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.
Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.*/

class Node{
    public:
        int endOfWord;
        char data;
        Node* children[26];
       
        Node(char ch){
            endOfWord = 0;
            data = ch;
            for(int i=0; i<26; i++) children[i] = NULL;
        }
};
class Trie {
public:
    Node* root;
    Trie() {
        
        Node* r = new Node('\0');
        root = r;
    }
    
    void insert( string word) {  //TC: O(N)
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
        }
        (curr->endOfWord)++;
    }
    void generateSubsets(int i,  string temp, string& s){ //TC: O(N * 2^N)
        if(i == s.size()){
            insert(temp);
            return;
        }
        generateSubsets(i+1, temp, s);
        
        temp.push_back(s[i]);
        
        generateSubsets(i+1, temp, s);
    }
    void collectStrings(Node* curr, string temp, vector<string>& res){ //TC: O(N * 2^N)
        
        if(curr->data != '\0') temp.push_back(curr->data);
        for(int i=1; i <= curr->endOfWord; i++) res.push_back(temp); //duplicate subsequences need to be considered too
        
        for(int i=0; i<26; i++){
            if(curr->children[i]) collectStrings(curr->children[i], temp, res);
        }
    }
};

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> res;
		    Trie t;
		    string temp;
		    
		    t.generateSubsets(0, temp, s);
		    t.collectStrings(t.root, temp, res);
		    
		    return res;
		}
};
