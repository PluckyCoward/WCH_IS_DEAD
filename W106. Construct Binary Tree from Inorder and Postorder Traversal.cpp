class Solution {
public:
    vector<int> in, post;
    
    int index;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        in = inorder;
        post = postorder;
        index = n - 1;
        TreeNode* res = dfs(0, index);
        return res;
    }
    
    TreeNode* dfs(int begin, int end) {
        if (begin > end)
            return NULL;
        int root = post[index--];
        TreeNode* node = new TreeNode(root);
        int pos = find(in.begin(), in.end(), root) - in.begin();
        node->right = dfs(pos + 1, end);
        node->left = dfs(begin, pos - 1);
        return node;
    }
};