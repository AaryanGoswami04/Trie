/*A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.*/
class Node{
    public:
        bool endOfWord;
        char data;
        Node* children[26];
       
        Node(char ch){
            endOfWord = false;
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
    
    void insert( string word) { //TC:O(N); SC:O(N)
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
        curr->endOfWord = true;
    }
    
    bool search( string word) { //TC:O(N)
        int n = word.size();
        Node* curr = root;

        for(int i=0; i<n; i++){
            int idx = word[i] - 'a';

            if(curr->children[idx] == NULL) return false;

            curr = curr->children[idx];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) { //TC:O(N)
        int n = prefix.size(); 
        Node* curr = root;

        for(int i=0; i<n; i++){
            int idx = prefix[i] - 'a';

            if(curr->children[idx] == NULL) return false;

            curr = curr->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
