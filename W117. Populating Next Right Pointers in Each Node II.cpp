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

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size(); 
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                if (i < size - 1) {
                    node->next = q.front(); 
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};