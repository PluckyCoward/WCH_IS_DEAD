class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> G(n, 0);
        for (auto i : edges) {
            G[i[1]] ++;
        }
        for (int i = 0; i < n; i++) {
            if (G[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};