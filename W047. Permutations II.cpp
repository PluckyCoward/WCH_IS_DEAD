class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> re;
        dfs(res, nums, re, used, nums.size(), 0);
        return res;        
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& re, vector<bool>& used, int n, int depth){
        if (depth == n)
            res.push_back(re);
        for (int i = 0; i < n; i++) {
            if (!used[i]){
                if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1])
                    continue;
                used[i] = true;
                re.push_back(nums[i]);
                dfs(res, nums, re, used, n, depth + 1);
                re.pop_back();
                used[i] = false;
            }
        }
    }

};