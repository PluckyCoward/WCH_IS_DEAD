//dp
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    }
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int, int>> tmp;
        for (int i = 0; i < height.size(); i++) {
            tmp.push_back({height[i], weight[i]});
        }
        sort(tmp.begin(), tmp.end(), cmp);
        vector<int> ans;
        for (auto i : tmp) {
            auto pos = lower_bound(ans.begin(), ans.end(), i.second);
            if (pos == ans.end())
                ans.push_back(i.second);
            else
                *pos = i.second;
        }
        return ans.size();
    }
};