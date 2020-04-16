class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size();
        while (l < r) {
            if (!judge(s[l])) {
                l++;
                continue;
            }
            if (!judge(s[r])) {
                r--;
                continue;
            }
            swap(s[l++], s[r--]);
        }
        return s;
    }
    
    bool judge(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};