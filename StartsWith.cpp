// Time complexity: O(word.size())
class TrieNode{
    public:
    char data;
    bool isterminal=true;
    TrieNode* children[26];
    TriedNode(char ch){
        data=ch;
        for(int i=0; i<26; i++)
            children[i]=NULL;
        isTerminal=false;
    }
}
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TreeNode('\0');
    }
    bool CheckUntil(TrieNode* root, string word){
        //base case
        if(word.size()==0)
            return true;
      
        int index=word[0]-'a';
        TrieNode* child;
      
        if(root->children[index] != NULL)   //Key is present
            child = root->children[index];
        else
            return false;
        return CheckUntil(child, word.substr(1));
    }
 
    bool StartsWith(string word) {
         return CheckUntil(root, word);
    }
};
