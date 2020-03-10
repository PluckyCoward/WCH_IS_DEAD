//dfs
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int pos){
        res.push_back(tmp);
        for (int i = pos; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            dfs(res, nums, tmp, i + 1);
            tmp.pop_back();
        }
    }

};