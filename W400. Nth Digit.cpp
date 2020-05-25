class Solution {
public:
    int findNthDigit(int n) {
        long long a = 9, d = 1;
        while (n - a * d > 0) {
            n -= a * d;
            a *= 10;
            d++;
        }
        int num = n / d + pow(10,d - 1);
        int pos = n % d;
        if (pos == 0) {
            num--;
            pos = d;
        }
        string str = to_string(num);
        return str[--pos] - '0';
    }
};