class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && find(i) != find(j)) {
                    parent[find(i)] = find(j);
                    res--;
                }
            }
        }
        return res;
    }
};