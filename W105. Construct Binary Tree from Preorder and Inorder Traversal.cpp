//dfs
class Solution {
public:
    vector<int> pre,in;
    int index = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        pre = preorder;
        in = inorder;
        return dfs(0, n - 1);
    }
    
    TreeNode* dfs(int begin, int end) {
        if (begin > end)
            return NULL;
        int root = pre[index++];
        TreeNode* node = new TreeNode(root);
        int pos = find(in.begin(), in.end(), root) - in.begin();
        node->left = dfs(begin, pos - 1);
        node->right = dfs(pos + 1, end);
        return node;
    }
};