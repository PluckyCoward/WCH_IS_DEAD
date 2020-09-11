class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> G(n);
        for (auto i : graph) {
            G[i[0]].push_back(i[1]);
        }
        vector<int> visited(n, 0);
        return dfs(G, visited, start, target);
    }

    bool dfs(vector<vector<int>> &G, vector<int> &visited, int start, int target) {
        if (start == target) return true;
        visited[start] = 1;
        for (auto i : G[start]) {
            if (visited[i] == 0 && dfs(G, visited, i, target))
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> G(n);
        for (auto i : graph) {
            G[i[0]].push_back(i[1]);
        }
        vector<int> visited(n, 0);
        stack<int> s;
        s.push(start);
        visited[start] = 1;
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            for (auto i : G[node]) {
                if (i == target) return true;
                if (!visited[i]) {
                    s.push(i);
                    visited[i] = 1;
                }
            }
        }
        return false;
    }
};