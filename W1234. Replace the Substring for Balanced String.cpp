class Solution {
public:
    int balancedString(string s) {
        vector<char> alphabet {'Q', 'W', 'E', 'R'};
        unordered_map<char,int> map;
        for (auto ch : s) {
            map[ch]++;
        }
        int average = s.size() / 4;
        bool balance = true;
        for (char ch : alphabet) {
            if (map[ch] != average)
                balance = false;
            map[ch] -= average; 
        }
        if(balance == true)
            return 0;
        int l = 0, r = 0, n = s.size(), res = n;
        while (l <= r && r < n) {
            map[s[r]]--;
            bool find = true;
            while (find) {
                for (char ch : alphabet) {
                   if (map[ch] > 0) {   
                       find = false;
                       break;
                   }
                }
                if(find == true){
                    res = min(res, r - l + 1);
                    map[s[l++]]++;
                }
            }
            r++;
        }
        return res;
    }
};