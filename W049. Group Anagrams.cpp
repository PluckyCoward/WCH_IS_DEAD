class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ma;
        vector<vector<string>> res;
        for (auto str:strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            ma[tmp].push_back(str);
        }
        for (auto m:ma){
            res.push_back(m.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        for (auto i = map.begin(); i != map.end(); ++i) {
            res.push_back(i->second);
        }
        return res;
    }
};
