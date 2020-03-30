//Hash Table + DFS
class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> map;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }

    string dfs(TreeNode* root){
        if (!root)
            return "#";
        string left = dfs(root->left);
        string right = dfs(root->right);
        string s = to_string(root->val) + " " + left + " " + right;
        map[s]++;
        if (map[s] == 2)
            res.push_back(root);
        return s;
    }
};