class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int j = int(nums.size()) - 1;
        while (j > 0 && nums[j - 1] >= nums[j]) {
            j--;
        }
        //不存在更大排列
        if (j == 0) {
            for (int i = 0; i < nums.size() / 2; i++) {
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return;
        }
        int m = int(nums.size()) - 1;
        while (m >= j) {
            if (nums[m] > nums[j - 1]) {
                break;
            }
            m--;
        }
        swap(nums[m], nums[j - 1]);
        int n = (nums.size() - j) / 2;
        int i = 0;
        while (n > 0) {
            swap(nums[j+i], nums[nums.size() - 1 - i]);
            i++;
            n--;
        }
        return;       
    }
};