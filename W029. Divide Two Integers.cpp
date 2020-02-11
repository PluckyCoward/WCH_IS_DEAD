class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool neg;
        neg = (dividend ^ divisor) < 0;
        unsigned int t = dividend == INT_MIN ? INT_MIN : abs(dividend);
        unsigned int d = divisor == INT_MIN ? INT_MIN : abs(divisor);
        unsigned int result = 0;
        for (int i = 31; i >= 0; i--) {
            if ((t >> i) >= d) {
                result += ((unsigned int)1) << i;
                t -= d << i;
            }
        }
        if (result == INT_MIN) {
            return INT_MIN;
        }
        else {
            return neg ? -(int)result : (int)result;
        }
    }
};