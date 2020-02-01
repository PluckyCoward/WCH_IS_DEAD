class Solution {
public:
    int myAtoi(string str) {
        int res=0;
        stringstream ss;
        ss << str;
        ss>>res;
        return res;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int pos = 0;
        int bol = 1;
        while (pos < str.length() && str[pos] == ' ') {
            pos++;
        }
        if (pos == str.length()) {
            return 0;
        }
        if (str[pos] == '-') {
            bol = -1;
            pos++;
        }
        else if (str[pos] == '+'){
            bol = 1;
            pos++;
        }
        while (pos < str.length() && str[pos] >= '0' && str[pos] <='9') {
            res = res * 10 + str[pos++] - '0';
            if(res > INT_MAX){
                if(bol == 1)
                    return INT_MAX;
                else return INT_MIN;
            }
        }
        return res * bol;
    }
};
