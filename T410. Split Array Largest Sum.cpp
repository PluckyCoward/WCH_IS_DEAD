class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1,vector<int>(m+1,INT_MAX));
        long long sum[10001] = {};
        dp[0][0] = 0;
        for(int i = 1;i <= n; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                for(int k = 0;k < i;k++){
                    dp[i][j] = min(dp[i][j],max(dp[k][j-1],(int)(sum[i] - sum[k])));
                }
            }
        }
        return dp[n][m];
    }
};