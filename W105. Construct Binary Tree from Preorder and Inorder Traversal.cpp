//dfs
class Solution {
public:
    vector<int> pre,in;

    int index = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (!n)
            return NULL;
        pre = preorder;
        in = inorder;
        TreeNode* res = build(0, n - 1);
        return res;
    }

    TreeNode* build(int begin, int end){
        if (begin > end)
            return NULL;
        int root = pre[index++];
        TreeNode* t = new TreeNode(root);
        int pos = find(in.begin() + begin, in.end() + end, root) - in.begin();
        t->left = build(begin, pos - 1);
        t->right = build(pos + 1, end);        
        return t;
    }
};