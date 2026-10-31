class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int minVal) {
        if (!node) return -1;
        if (node->val > minVal) {
            return node->val;
        }

        int left = dfs(node->left, minVal);
        int right = dfs(node->right, minVal);

        if (left != -1 && right != -1) {
            return min(left, right);
        }
        
        return left != -1 ? left : right;
    }
};
