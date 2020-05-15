//递归
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL && sum - root->val == 0)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};