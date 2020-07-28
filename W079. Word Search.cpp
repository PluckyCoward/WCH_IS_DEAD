//dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int w){
        if (board[i][j] != word[w])
            return false;
        if (w == word.length() - 1)
            return true;
        char tmp = board[i][j];
        board[i][j] = 0;
        if ((i - 1 >= 0 && dfs(board, word, i - 1, j, w + 1))
            ||(j - 1 >= 0 && dfs(board, word, i, j - 1, w + 1))
            ||(i + 1 <= board.size() - 1 && dfs(board, word, i + 1, j, w + 1))
            ||(j + 1 <= board[0].size() - 1 && dfs(board, word, i, j + 1, w + 1))) {
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
};

//dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (board[i][j] != word[index])
            return false;
        if (word.size() - 1 == index)
            return true;
        index++;
        char tmp = board[i][j];
        board[i][j] = '\0';
        if ((i > 0 && dfs(board, word, index, i - 1, j)) || (j > 0 && dfs(board, word, index, i, j - 1)) || (i < board.size() - 1 && dfs(board, word, index, i + 1, j) || (j < board[0].size() - 1 && dfs(board, word, index, i, j + 1))))
            return true;
        board[i][j] = tmp;
        return false;
    }
};