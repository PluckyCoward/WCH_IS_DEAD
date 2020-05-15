//dfs
class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* node, int sum, vector<int> tmp) {
        tmp.push_back(node->val);
        if (node->left == NULL && node->right == NULL && sum - node->val == 0)
            res.push_back(tmp);
        if (node->left)
            dfs(node->left, sum - node->val, tmp);
        if (node->right)
            dfs(node->right, sum - node->val, tmp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return res;
        vector<int> tmp;
        dfs(root, sum, tmp);
        return res;
    }
};
