class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestNum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = int(nums.size()) - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(closestNum - target)) {
                    closestNum = sum ;
                }
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else return target;
            }
        }
        return closestNum;
    }
};