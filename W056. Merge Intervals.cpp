class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), [&,this](vector<int> &v1, vector<int> &v2) {return v1[0] < v2[0];});
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> tmp = intervals[i];
            while (i + 1 < intervals.size() && tmp[1] >= intervals[i + 1][0]) {
                i++;
                tmp[1] = max(intervals[i][1], tmp[1]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};