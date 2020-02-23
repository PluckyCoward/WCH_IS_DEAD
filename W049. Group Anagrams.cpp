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