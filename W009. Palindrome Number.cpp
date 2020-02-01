class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = 0;
        long y = 0;
        int m = x;
        while(m != 0){
            temp = m % 10;
            y = y * 10 + temp;
            m = m / 10;
        }
        return y == x;
    }
};