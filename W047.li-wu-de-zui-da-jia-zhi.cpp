//dp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                dp[i][j] = grid[i - 1][j - 1] + max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
};