//dfs
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root != NULL)
            dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        res.push_back(root->val);
        if(root->left != NULL)
            dfs(root->left);
        if(root->right != NULL)
            dfs(root->right);
    }
};