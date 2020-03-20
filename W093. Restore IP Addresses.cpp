//dfs
class Solution {
public:
    vector<string> res;
    
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(s, 0, ip);
        return res;
    }
    
    void dfs(string s, int n, string ip) {
        if (n == 4) {
            if (s.empty())
                res.push_back(ip);
        }
        else{
            for (int i = 1; i < 4; i++) {
                if (s.size() < i)
                    break;
                int val = stoi(s.substr(0, i));
                if (val > 255 || i != to_string(val).size())
                    continue;
                dfs(s.substr(i), n + 1, ip + s.substr(0, i) + (n == 3 ? "" : "."));
            }
        }
        return;
    }
};