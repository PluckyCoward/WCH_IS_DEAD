class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = int(nums.size());
        for (int a = 0; a < size - 3; a++) {
            if (a > 0 && nums[a] == nums[a-1])
                continue;
            for (int b = a + 1; b < size - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b-1])
                    continue;
                int i = b + 1, j = size - 1;
                while (i < j) {
                    int sum = nums[a] + nums[b] + nums[i] + nums[j];
                    if(sum < target)
                        i++;
                    else if(sum>target)
                        j--;
                    else{
                        res.push_back(vector<int>{nums[a],nums[b],nums[i],nums[j]});
                        while(i < j && nums[i] == nums[++i]);
                        while(i < j && nums[j] == nums[--j]);
                    }
                }
            }
        }
        return res;
    }
};