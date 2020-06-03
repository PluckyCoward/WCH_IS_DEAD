//dfs
class Solution {
public:
    Node* connect(Node* root) {
        return dfs(root);
    }
    
    Node* dfs(Node* node) {
        if (!node)
            return NULL;
        if (node->left)
            node->left->next = node->right;
        if (node->right)
            node->right->next = node->next ? node->next->left : NULL;
        dfs(node->left);
        dfs(node->right);
        return node;
    }
};