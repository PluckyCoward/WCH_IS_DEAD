class Solution {
public:
    bool isUnique(string astr) {
        int mark = 0;
        for (char c : astr) {
            if (mark & (1 << (c - 'a')))
                return false;
            else
                mark |= 1 << (c - 'a');
        }
        return true;
    }
};
