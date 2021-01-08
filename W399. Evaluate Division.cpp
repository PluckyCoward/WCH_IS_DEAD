class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    string find(string x) {
        if (parent[x] != x) {
            string tmp = find(parent[x]);
            weight[x] *= weight[parent[x]];
            parent[x] = tmp;
        }
        return parent[x];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            parent[a] = a, parent[b] = b;
            weight[a] = 1, weight[b] = 1;
        }
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            string ra = find(a), rb = find(b);
            parent[ra] = rb;
            weight[ra] = values[i] * weight[b] / weight[a];
        }
        for(auto q : queries) {
            string a = q[0], b = q[1];
            if(!parent.count(a) || !parent.count(b) || find(a) != find(b))
                res.push_back(-1.0);
            else
                res.push_back(weight[a] / weight[b]);
        }
        return res;
    }
};