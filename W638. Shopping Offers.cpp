class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return shopping(price, special, needs);
    }
    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int i = 0, res = caculateNeedPrice(price, needs);
            for (auto s : special) {
                vector<int> tmp(needs);
                for (i = 0; i < needs.size(); i++) {
                    int d = tmp[i] - s[i];
                    if (d < 0)
                        break;
                    tmp[i] = d;
                }
                if (i == needs.size())
                    res = min(res, s[i] + shopping(price, special, tmp));
            }
            return res;
    }

    int caculateNeedPrice(vector<int> p, vector<int> n) {
        int sum = 0;
        for (int i = 0; i < p.size(); i++) {
            sum += p[i] * n[i];
        }
        return sum;
    }
};
