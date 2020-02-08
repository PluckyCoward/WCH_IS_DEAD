class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    
    void generate(vector<string> &res, string ans, int open, int close, int n){
        if (open > n || close > n)
            return;
        if (open == n && close == n)
            res.push_back(ans);
        if (open >= close) {
            string ans1 = ans;
            generate(res, ans+'(', open + 1, close, n);
            generate(res, ans1+')', open, close + 1, n);
        }
    }
};