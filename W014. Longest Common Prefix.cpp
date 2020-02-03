class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = (strs.size() == 0) ? "" : strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(res) != 0) {
                res = (res == "") ? "" : res.substr(0, res.length() - 1);
            }
        }
        return res;
    }
};
