class Djset {
public:
    vector<int> parent;
    vector<int> rank;
    
    Djset(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
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
            rank[rx] += rank[ry];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        Djset ds(n);
        for (auto& e : pairs) {
            ds.merge(e[0], e[1]);
        }

        unordered_map<int, vector<int> > map;
        for (int i = 0; i < n; i++) {
            map[ds.find(i)].push_back(s[i]);
        }

        for (auto& [x, vec] : map) {
            sort(vec.begin(), vec.end(), greater<int>());
        }
        for (int i = 0; i < n; i++) {
            int x = ds.find(i);
            s[i] = map[x].back();
            map[x].pop_back();
        }
        return s;

    }
};