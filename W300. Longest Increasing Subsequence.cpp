//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1 ;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

//DP + Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail = vector<int>(nums.size());
       if (nums.size() < 2) {
           return nums.size();
       }
        tail[0]=nums[0];
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (tail[res - 1] < nums[i]) {
                tail[res++] = nums[i];
            }
            else{
                int pos = lower_bound(tail.begin() , tail.begin()  + res, nums[i]) - tail.begin();
                tail[pos] = nums[i];
            }
        }
        return res;
    }
};
