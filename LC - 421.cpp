class Solution {
    struct TrieNode {
        TrieNode* children[2] = {nullptr, nullptr};
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        
        for (int num : nums) {
            TrieNode* curr = root;
            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!curr->children[bit]) {
                    curr->children[bit] = new TrieNode();
                }
                curr = curr->children[bit];
            }
        }
        
        int max_xor = 0;
        for (int num : nums) {
            TrieNode* curr = root;
            int curr_xor = 0;
            for (int i = 30; i >= 0; i--) {
                int bit = (num >> i) & 1;
                int toggled = 1 - bit;
                if (curr->children[toggled]) {
                    curr_xor |= (1 << i);
                    curr = curr->children[toggled];
                } else {
                    curr = curr->children[bit];
                }
            }
            max_xor = max(max_xor, curr_xor);
        }
        
        return max_xor;
    }
};
