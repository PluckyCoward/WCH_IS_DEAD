class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int r = A.size() - 1;
        int l = 0;
        vector<int> res;
        while (l <= r) {
            if (A[l] * A[l] < A[r] * A[r]) {
                res.push_back(A[r] * A[r]);
                r--;
            }
            else {
                res.push_back(A[l] * A[l]);
                l++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};