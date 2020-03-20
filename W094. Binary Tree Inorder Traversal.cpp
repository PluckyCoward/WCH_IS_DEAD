/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return res;
        if (root->left)
            inorderTraversal(root->left);
        res.push_back(root->val);
        if (root->right)
            inorderTraversal(root->right);
        return res;
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* rt = root;
        while (rt || s.size()) {
            while (rt) {
                s.push(rt);
                rt = rt->left;
            }
            rt = s.top();
            s.pop();
            res.push_back(rt->val);
            rt = rt->right;
        }
        return res;
    }
};