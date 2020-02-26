//Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                return false;
            k = max(k, i + nums[i]);
            if (k >= nums.size() - 1)
                break;
        }
        return true;
    }
};

//DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int jump = (i + nums[i]) < (nums.size() - 1) ? i + nums[i] : nums.size() - 1;
            for (int j = i + 1; j <= jump; j++) {
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};