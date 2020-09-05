//Math
class Solution {
public:
    bool divisorGame(int N) {
        if (N % 2 == 0)
            return true;
        else
            return false;
    }
};

//dp
class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N + 2,0);
        dp[2] = 1;
        for (int i = 3; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (N % j == 0 && dp[j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};