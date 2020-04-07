//hashmap
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab;
        int res = 0;
        for (auto a : A) {
            for (auto b : B) {
                int sum = a + b;
                ab[sum]++;
            }
        }
        for (auto c : C) {
            for (auto d : D){
                int sum = c + d;
                if (ab.count(-sum)) {
                    res = res + ab[-sum];
                }
            }
        }
        return res;
    }
};