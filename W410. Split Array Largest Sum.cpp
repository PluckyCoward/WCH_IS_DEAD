//dp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        vector<long long> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for (int i = 2; i <= n; i++){
            dp[i][1] = sum[i];
        }
        for (int i = 1; i <= m; i++){
            dp[1][i] = nums[0];
        }
        for (int i = 2; i < n + 1; i++) {
            for (int j = 2; j < m + 1; j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], (int)(sum[i] - sum[k])));
                }
            }
        }
        return dp[n][m];       
    }
};