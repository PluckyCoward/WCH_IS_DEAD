class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int begin = rounds[0];
        int end = rounds[rounds.size() - 1];
        if (begin <= end) {
            for (int i = begin; i <= end; i++) {
                res.push_back(i);
            }
        }
        else {
            for (int i = 1; i <= end; i++) {
                res.push_back(i);
            }
            for (int i = begin; i <= n; i++) {
                res.push_back(i);
            }
        }
        return res;
    }
};