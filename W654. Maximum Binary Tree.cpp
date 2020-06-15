class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size());
    }
    
    TreeNode* constructTree(vector<int>& nums, int left, int right) {
        if (left >= right)
            return NULL;
        int index = left;
        int max = INT_MIN;
        for (int i = left; i < right; i++) {
            if (nums[i] > max) {
                index = i;
                max = nums[i];
            }
        }
        TreeNode* node = new TreeNode(max);
        node->left = constructTree(nums, left, index);
        node->right = constructTree(nums, index + 1, right);
        return node;
    }
};