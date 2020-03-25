//dfs
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int level){
        if (root == NULL)
            return;
        if (level == res.size())
            res.emplace_back();
        if (level % 2 == 0) {
            res[level].push_back(root->val);
        }
        else{
            res[level].insert(res[level].begin(), root->val);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};

//bfs
class Solution {
public:  
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> res;
        vector<int> level;
        if (root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                if (l % 2 == 0)
                    level.push_back(cur->val);
                else
                    level.insert(level.begin(), cur->val);
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            l++;
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};