class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxNum = 0;
        for(auto n : nums) {
            maxNum = max(maxNum, n);
        }
        vector<int> v(maxNum + 1), dp(maxNum + 1);
        for(auto n : nums)
            v[n]++;
        dp[1] = v[1];
        for (int i = 2; i <=maxNum; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + v[i] * i);
        }
        return dp[maxNum];
    }
};