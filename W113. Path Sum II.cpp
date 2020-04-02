//dfs
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return res;
        vector<int> tmp;
        dfs(root, sum, tmp);
        return res;
        
    }
    
    void dfs(TreeNode* root, int sum, vector<int> tmp){
        tmp.push_back(root->val);
        if (root->left == NULL && root->right ==NULL && sum - root->val == 0) {
            res.push_back(tmp);
        }
        if (root->left)
            dfs(root->left, sum - root->val, tmp);
        if (root->right)
            dfs(root->right, sum - root->val, tmp);
    }
};