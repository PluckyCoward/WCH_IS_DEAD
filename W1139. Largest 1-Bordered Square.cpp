//dp
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j<= n; j++) {
                if (grid[i - 1][j - 1] == 1) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                    int len = min(dp[i][j][0], dp[i][j][1]);
                    while (len > 0) {
                        if (dp[i][j - len + 1][1] >= len && dp[i - len + 1][j][0] >= len)
                            break;
                        len--;
                    }
                    res = max(res, len);
                }
            }
        }
        return res * res;

    }
};