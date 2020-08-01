//Hashmap
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> map;
        for (auto n : nums) {
            map[n]++;
        }
        for (auto n : nums) {
            if (--map[n] >= 0 && --map[target - n] >= 0) {
                res.push_back({n, target - n});
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> map;
        for (auto n : nums) {
            if (map[target - n] > 0) {
                map[target - n] --;
                res.push_back({n, target - n});
            }
            else {
                map[n]++;
            }
        }
        return res;
    }
};