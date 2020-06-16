class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if (!root)
            return res;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            res.emplace_back(node->val);
            for (auto i : node->children) {
                st.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};