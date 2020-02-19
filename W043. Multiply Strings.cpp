class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = int(num1.length());
        int l2 = int(num2.length());
        if (l1 < 1 || l2 < 1)
            return "";
        string res(l1 + l2,'0');
        for (int i = l1 - 1; i >= 0; i--) {
            int n1 = num1[i] - '0';
            for (int j = l2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = res[i + j + 1] -'0' + n1 * n2;
                res[i + j + 1] = sum % 10 + '0';
                res[i + j] += sum / 10;
            }
        }
        for (int i = 0; i < l1 + l2; i++) {
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";        
    }
};