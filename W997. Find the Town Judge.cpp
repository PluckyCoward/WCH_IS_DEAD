//Graph
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // in - out
        vector<int> G(N + 1, 0);
        for (auto i : trust) {
            G[i[0]]--;
            G[i[1]]++;
        }
        for (int i = 1; i < G.size(); i++) {
            if (G[i] == N - 1) return i;
        }
        return -1;
    }
};