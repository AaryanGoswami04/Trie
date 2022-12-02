//Time complexity: O(N^2)
class TrieNode{
    public:
    vector<TrieNode*> children;
    char data;
    TrieNode(char ch){
        data = ch;
        children = vector<TrieNode*> (26, NULL);
    }
};
int countDistinctSubstring(string s)
{
    int cnt=0;
    TrieNode* root = new TrieNode ('\0');
    int len = s.size();
    for(int i=0; i<len; i++){
        TrieNode* curr=root;
        for(int j=i; j<len; j++){
          
            int index = s[j]-'a';
            if(!curr->children[index]){
                cnt++;
                curr->children[index]=new TrieNode(s[j]);
            }
            curr=curr->children[index];
          
        }
    }
    return cnt+1;  //Count empty string as well
}
