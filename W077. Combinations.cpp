class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& tmp, int step, int n, int k){
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = step; i <= n; i++) {
            tmp.push_back(i);
            dfs(res, tmp, i + 1, n, k - 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, 1, n, k);
        return res;
    }
};