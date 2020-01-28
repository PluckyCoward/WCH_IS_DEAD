//DP
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000]={0};
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        int start = 0;
        int max = 1;
        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
            if (i < len - 1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }
        for (int l = 3; l <= len; l++) {
            for (int i = 0; i + l - 1 < len; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start, max);
    }
};

//Manacher
class Solution {
public:
    string longestPalindrome(string s) {
        int len = (int) s.length();
        if (len < 1) {
            return "";
        }
        
        //new s with "#"
        string s1;
        for (int i = 0; i < len; i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";
        
        len = (int) s1.length();
        int maxRight = 0; //最右回文右边界位置
        int pos = 0; //对称中心位置
        int maxRL = 0; //最大回文半径长度
        int maxPos = 0; //最大回文串对称轴位置
        int* RL = new int[len]; //回文半径数组
        memset(RL, 0, len * sizeof(int));
        for (int i = 0; i < len; i++) {
            if (i < maxRight) {
                RL[i] = min(RL[2 * pos - i], maxRight - i);
            }
            else{
                RL[i] = 1;
            }
            while (i - RL[i] >= 0 && i + RL[i] < len && s1[i - RL[i]] == s1[i + RL[i]]) {
                RL[i] += 1;
            }
            
            if (RL[i] + i - 1 > maxRight) {
                maxRight = RL[i] + i - 1;
                pos = i;
            }
            if (maxRL <= RL[i]) {
                maxRL = RL[i];
                maxPos = i;
            }
        }
        return s.substr((maxPos - maxRL + 1) / 2, maxRL - 1);
    }
};
