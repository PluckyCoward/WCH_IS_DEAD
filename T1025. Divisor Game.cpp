//dp
class Solution {
public:
    bool divisorGame(int N) {
        int dp[1001]= {};
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3;i <= N; i++){
            for(int j = 1;j < i;j++){
                if(N % j == 0 && dp[j]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};

//math
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};