class Djset {
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    Djset(int n) : parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry])
                swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx] += 1;
            count--;
        }
    }
    int get_count() {
        return count;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Djset ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.merge(i, j);
                }
            }
        }
        return n - ds.get_count();
    }
};