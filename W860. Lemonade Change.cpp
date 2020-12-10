class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto bill : bills) {
            if (bill == 5)
                five++;
            if (bill == 10) {
                ten++;
                if(--five < 0)
                    return false;
            }
            if (bill == 20) {
                if (ten > 0) {
                    ten--;
                    if (--five < 0)
                        return false;
                }
                else {
                    five -= 3;
                    if(five < 0)
                        return false;
                }
            }
        }
        return true;
    }
};