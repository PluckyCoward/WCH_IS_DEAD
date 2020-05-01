//dfs
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrder(TreeNode* root){
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int level){
        if (root == NULL)
            return;
        if (res.size() == level)
            res.emplace_back();
        res[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};

//bfs
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(level);
        }
        return res;
    }
};