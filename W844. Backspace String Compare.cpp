//Two Pointers
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1;
        int j = T.size() - 1;
        int skipS = 0, skipT = 0;
        while(i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    i--;
                    skipS++;
                }
                else if (skipS > 0) {
                    i--;
                    skipS--;
                }
                else {
                    break;
                }
            }
            while (j >= 0) {
                if (T[j] == '#') {
                    j--;
                    skipT++;
                }
                else if (skipT > 0) {
                    j--;
                    skipT--;
                }
                else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j])
                    return false;
            }
            else {
                if (i >= 0 || j >= 0)
                    return false;
            }
            i--;
            j--;
        }
        return true;
    }
};