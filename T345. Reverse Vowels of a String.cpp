class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<int>s1 = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0,right = s.length() - 1;
        while(left < right){
            if(s1.count(s[left]) == 0){
                left++;
                continue;
            }
            if(s1.count(s[right]) == 0){
                right--;
                continue;
            }
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }
};