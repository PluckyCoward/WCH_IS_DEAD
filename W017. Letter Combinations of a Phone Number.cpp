class Solution {
public:
    map<char, string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> res;
    string cur;
    
    void dfs(string digit){
        if (!digit.size())
            res.push_back(cur);
        else{
            char num = digit[0];
            string letter = mp[num];
            for (int i = 0; i < letter.size(); i++) {
                cur.push_back(letter[i]);
                dfs(digit.substr(1));
                cur.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (!digits.size())
            return res;
        dfs(digits);
        return res;
    }
};