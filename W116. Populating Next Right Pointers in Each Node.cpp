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

//dfs
class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }

    void dfs(Node* node) {
        if (!node) return;
        if (node->left)
            node->left->next = node->right;
        if (node->right)
            node->right->next = node->next ? node->next->left : NULL;
        dfs(node->left);
        dfs(node->right);
    }
};

//Queue
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                Node* node = q.front();
                q.pop();
                if(i != cnt - 1)
                    node->next = q.front();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
        }
        return root;
    }
};