class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        for (int i = 0; i < row; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    A[i][j] ^= 1; 
                }
            }
        }
        int sum = row;
        for (int j = 1; j < col; j++) {
            int tmp = 0;
            for (int i = 0; i < row; i++) {
                if (A[i][j] == 1)
                    tmp++;
            }
            tmp = max(tmp, row - tmp);
            sum = sum << 1;
            sum += tmp;
        }
        return sum;
    }
};