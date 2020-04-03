//dfs
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            auto tmp = root->left;
            while (tmp->right != NULL) {
                tmp = tmp->right;
            }
            tmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return;        
    }
};