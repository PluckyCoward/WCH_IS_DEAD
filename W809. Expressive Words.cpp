class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<char> alphabet_S = alphabet(S);
        vector<int> alphabet_count_S = alphabet_count(S);
        int i;
        int res = 0;
        for (auto word : words) {
            vector<char> alphabet_word = alphabet(word);
            vector<int> alphabet_count_word = alphabet_count(word);
            if (alphabet_S != alphabet_word)
                continue;
            else {
                for (i = 0; i < alphabet_count_word.size(); i++) {
                    if (alphabet_count_S[i] < alphabet_count_word[i] || (alphabet_count_S[i] != alphabet_count_word[i] && alphabet_count_S[i] < 3))
                        break;
                }
                if (i == alphabet_count_word.size())
                    res++;
            }
        }
        return res;
    }
    
    vector<int> alphabet_count(string s) {
        vector<int> res;
        int index = 0;
        res.push_back(1);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]){
                res.push_back(1);
                index++;
            }
            else {
                res[index]++;
            }
        }
        return res;
    }

    vector<char> alphabet(string s) {
        vector<char> res;
        res.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]){
                res.push_back(s[i]);
            }
        }    
        return res;    
    }
};