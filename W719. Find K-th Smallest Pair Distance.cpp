//Binary Search
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            int count = count_pairs(nums, mid);
            if (count < k)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }

    int count_pairs(vector<int>& nums, int distance){
        int count = 0, r = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            while ((r < nums.size()) && (nums[r] - nums[i] <= distance)) {
                r++;
            }
            count += r - i - 1;
        }
        return count;
    }
};