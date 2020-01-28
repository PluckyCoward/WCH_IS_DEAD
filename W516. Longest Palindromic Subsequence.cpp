class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000]={0};
        int len = s.length();
        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = i + l - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        return dp[0][len-1];
    }
};