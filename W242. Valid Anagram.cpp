class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int a[26] = {};
        for (auto c : s) {
            a[c - 'a']++;
        }
        for (auto c : t) {
            a[c - 'a']--;
            if (a[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};