class Solution {
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int getSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        int s = getSum(root); 
        freq[s]++;
        maxFreq = max(maxFreq, freq[s]);
        traverse(root->left);
        traverse(root->right);
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        vector<int> res;
        for (auto& [sum, count] : freq) {
            if (count == maxFreq) res.push_back(sum);
        }
        return res;
    }
};
