class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.length();
        int i = 1;
        int m = 0;
        while (i < n && s[i - 1] <= s[i]) {
            i++;
        }
        if (i < n) {
            while (i > 0 && s[i - 1] > s[i]) {
                s[i - 1] -= 1; 
                i--;
            }
            for (i = i + 1; i < n; i++) {
                s[i] = '9';
            }
        }
        return stoi(s);
    }
};