class Solution {
public:
    bool isPerfectSquare(int num) {  
        int l = 0, r = num / 2 + 1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long square = mid * mid;
            if (square == num) {
                return true;
            }
            if (square < num)
                l = mid + 1;
            if (square > num)
                r = mid - 1;
        }
        return false;
    }
};