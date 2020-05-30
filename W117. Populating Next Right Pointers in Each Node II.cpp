//dfs
class Solution {
public:
    Node* connect(Node* root) {
        if(root && (root->left || root->right)){
            if(root->left and root->right) 
                root->left->next = root->right;
            Node *node = root->right ? root->right : root->left;
            Node *head = root->next;
            while (head && !(head->left || head->right)){
                head = head->next;
            }
            node->next = head ? (head->left ? head->left : head->right) : NULL;
            connect(root->right);
            connect(root->left);
        }
        return root;
    }
};