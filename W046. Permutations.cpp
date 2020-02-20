class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, int n, int first){
        if (first == n)
            res.push_back(nums);
        for (int i = first; i < n; i++) {
            swap(nums[first], nums[i]);
            dfs(res, nums, n, first + 1);
            swap(nums[first], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(res, nums, nums.size(), 0);
        return res;
    }

};