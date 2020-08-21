class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> g(N);
        vector<int> res(N, 0);
        for (int i = 0; i < paths.size(); i++) {
            g[paths[i][0] - 1].push_back(paths[i][1] - 1);
            g[paths[i][1] - 1].push_back(paths[i][0] - 1);
        }
        for (int i = 0; i < N; i++) {
            set<int> col = {1,2,3,4};
            for (int j = 0; j < g[i].size(); j++) {
                col.erase(res[g[i][j]]);
            }
            res[i] = *col.begin();
        }
        return res;
    }
};