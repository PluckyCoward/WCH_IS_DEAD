//dfs
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* node) {
        if (node == NULL)
            return;
        if (node->left)
            dfs(node->left);
        if (node->right);
            dfs(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};

//迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (root == NULL)
            return res;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            res.push_back(node->val);
            s.pop();
            if (node->left)
                s.push(node->left);
            if(node->right)
                s.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};