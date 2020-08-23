class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int index = 1;
        int max = 0;
        for (int i = 0; i < piles.size() / 3; i++) {
            max += piles[index];
            index += 2;
        }
        return max;
    }
};