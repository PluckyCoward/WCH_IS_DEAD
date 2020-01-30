class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> rows(min(numRows, (int) s.length()));
        int curRow = 0;
        bool isDown = false;
        for(char c : s){
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
                isDown = !isDown;
            curRow += isDown ? 1 : -1;
        }
        string res;
        for(string row : rows){
            res += row;
        }
        return res;
    }
};