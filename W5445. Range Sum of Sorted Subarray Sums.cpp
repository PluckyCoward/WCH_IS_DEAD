class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        int ans = 0;
        int last;
        for (int i = 0; i < n; i++) {
            last = 0;
            for (int j = i; j < n; j++) {
                last += nums[j];
                res.push_back(last);
            }
        }
        sort(res.begin(), res.end());
        for(int i = left - 1; i < right; i++) {
            ans += res[i];
        }
        return ans % int(pow(10,9) + 7);
    }
};