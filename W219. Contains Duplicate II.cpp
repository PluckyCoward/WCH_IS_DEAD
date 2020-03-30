//hash map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int index = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            auto tmp = map.find(nums[i]);
            if (tmp != map.end()){
                if (i - tmp->second <= k)
                    return true;
                else
                    tmp->second = i;
            }
            else
                map[nums[i]] = i;
        }
        return false;
    }
};