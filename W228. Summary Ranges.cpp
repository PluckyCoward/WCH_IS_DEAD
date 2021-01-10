class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (j + 1 == n || nums[j] + 1 != nums[j + 1]) {
                string tmp = to_string(nums[i]);
                if (i != j)
                    tmp.append("->").append(to_string(nums[j]));
                res.push_back(tmp);
                i = j + 1;
            }
        }
        return res;
    }
};