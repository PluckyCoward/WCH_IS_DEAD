class Solution {
public:
    vector<int> res;
    bool backtrack(string &S, int pos) {
        if (pos == S.length())
            return res.size() >= 3;
        for (int i = pos; i < S.length(); i++) {
            if (i > pos && S[pos] == '0')
                break;
            long long num = stoll(S.substr(pos, i - pos + 1));
            if (num > INT_MAX) break;
            if (res.size() >= 2) {
                long long sum = 0;
                sum = sum + res[res.size() - 1] + res[res.size() - 2];
                if (num < sum)
                    continue;
                else if (num > sum)
                    break;
            }
            res.push_back(num);
            if(backtrack(S, i + 1))
                return true;
            res.pop_back();
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string S) {
        backtrack(S, 0);
        return res;
    }
};