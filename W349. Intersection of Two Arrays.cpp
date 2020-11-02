class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> set (nums1.begin(), nums1.end());
        for (auto i : nums2) {
            if (set.count(i) > 0)
                res.insert(i);
        }
        return vector<int> (res.begin(), res.end());
    }
};