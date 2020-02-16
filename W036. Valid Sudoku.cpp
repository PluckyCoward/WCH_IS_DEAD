class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(10,vector<int>(10,0));
        vector<vector<int>> columns(10,vector<int>(10,0));
        vector<vector<int>> boxes(10,vector<int>(10,0));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num!='.') {
                    int n = int(num - '0');
                    int box_index = (i / 3) * 3 + j / 3;
                    rows[i][n]++;
                    columns[j][n]++;
                    boxes[box_index][n]++;
                    
                    if (rows[i][n] > 1 || columns[j][n] > 1 || boxes[box_index][n] > 1)
                        return false;
                    
                }
            }
        }
        return true;
        
    }
};