//dfs
class Solution {
public:
    vector<int> node;
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        while (head) {
            node.push_back(head->val);
            head = head->next;
        }
        return dfs(0, node.size() - 1);
    }
    
    TreeNode* dfs(int left, int right){
        if (left > right) {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(node[mid]);
        if (left < right){
            root->left = dfs(left, mid - 1);
            root->right = dfs(mid + 1, right);
        }
        return root;
    }
};