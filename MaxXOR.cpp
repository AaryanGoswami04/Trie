//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
//TC: O(N)
//SC:O(N)
class TrieNode{
    public:
    TrieNode* children[2];
    int data;
    TrieNode(int bit){
        data = bit;
        for(int i=0; i<2; i++)
            children[i] = NULL;
    }
};
class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode(0);
        }
       void insert(int num){
            TrieNode* curr = root;

            for(int i=31; i>=0; i--){
                int bit = (num >> i) & 1;
                if(curr->children[bit] == NULL)
                    curr->children[bit] = new TrieNode(bit);
                curr =  curr->children[bit];
            }
        }
        int getMax(int num){
            TrieNode* curr = root;
            int maxi = 0;

            for(int i=31; i>=0; i--){
                 int bit = (num >> i) & 1;
                 if(curr->children[1-bit]){
                    maxi = maxi ^ (1<<i);
                    curr = curr->children[1-bit];
                 }
                 else
                    curr = curr->children[bit];
            }
            return maxi;
        }
};
class Solution {
public:
    Trie t;
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums)
            t.insert(i);
        for(auto i:nums)
            ans = max(ans, t.getMax(i));
        return ans;
    }
};
  
