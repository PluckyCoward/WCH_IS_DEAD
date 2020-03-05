class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string tmp;
        for (auto c : path ) {
            if (c == '/') {
                if (tmp == ".." && !st.empty()) {
                    st.pop();
                }
                else if (tmp != ".." && tmp != "." && !tmp.empty()){
                    st.push(tmp);
                }
                tmp.clear();
            }
            else{
                tmp += c;
            }
        }
        string res;
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty())
            res = "/";
        return res;
    }
};