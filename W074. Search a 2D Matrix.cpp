class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        int pid,pe;
        while (l <= r) {
            pid = (l + r) / 2;
            pe = matrix[pid / n][pid % n];
            if (target == pe)
                return true;
            else{
                if (target < pe)
                    r = pid - 1;
                else
                    l = pid + 1;
            }
        }
        return false;

    }
};