//dfs
class Solution {
public:
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        if (res.size() < 1)
            return true;
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};

//递归
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long low, long high) {
        if (root == NULL)
            return true;
        else if (root->val <= low || root->val >= high)
            return false;
        return helper(root->left, low, root->val) && helper(root->right, root->val, high);
    }
};