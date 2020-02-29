class Solution {
public:
    string getPermutation(int n, int k) {
        string s = string("123456789").substr(0,n);
        for(int j = 1; j < k; ++j) next_permutation(s.begin(), s.end()); 
        return s;
    }
};

//Cantor expansion
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string s = string("123456789").substr(0,n);
        const int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
        k--;
        while(k > 0)
        {
            int i = k/fac[n - 1];
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            n--;
        }
        return res + s;
    }
};