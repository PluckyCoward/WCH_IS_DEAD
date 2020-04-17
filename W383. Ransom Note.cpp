//String
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26, 0);
        for (int i = 0; i < magazine.size(); i++){
            letters[magazine[i] - 'a'] += 1;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            letters[ransomNote[i] - 'a'] -= 1;
            if (letters[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};