class Solution {
public:
    vector<int> in,post;
    
    int index;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (!n) return NULL;sy
        in = inorder;
        post = postorder;
        index = n - 1;
        TreeNode* res = build(0, n - 1);
        return res;
    }
    
    TreeNode* build(int start, int end){
        if (start > end)
            return NULL;
        int root = post[index--];
        TreeNode* t = new TreeNode(root);
        int pos = find(in.begin() + start, in.end() + end, root) - in.begin();
        t->right = build(pos + 1, end);
        t->left = build(start, pos - 1);
        return t;
    }
};