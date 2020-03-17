//dfs
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int pos){
        res.push_back(tmp);
        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            dfs(res, nums, tmp, i + 1);
            tmp.pop_back();
        }
    }
};