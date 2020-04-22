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

//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* rt = root;
        while(rt || s.size()){
            while (rt){
                s.push(rt);
                res.push_back(rt->val);
                rt = rt->left;
            }
            rt = s.top();
            s.pop();
            rt = rt->right;
        }
        return res;
    }
};