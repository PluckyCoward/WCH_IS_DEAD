typedef pair<int,int> PAIR;
bool cmp(const PAIR& l, const PAIR& r) {
    return l.second > r.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto num : nums){
            map[num]++;
        }
        vector<PAIR> tmp(map.begin(),map.end());
        sort(tmp.begin(), tmp.end(), cmp);
        for (int i = 0; i < k; i++) {
            res.push_back(tmp[i].first);
        }
        return res;        
    }
};