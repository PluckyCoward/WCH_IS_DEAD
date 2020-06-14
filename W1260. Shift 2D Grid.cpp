class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res = grid;
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m * n);
        vector<int> tmp;
        vector<int> tmp_res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp.push_back(grid[i][j]);
            }
        }
        tmp_res = tmp;
        for (int i = 0; i < m * n; i++) {
            tmp_res[(i + k) % (m * n)] = tmp[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = tmp_res[i * n + j];
            }
        }
        return res;
    }
};