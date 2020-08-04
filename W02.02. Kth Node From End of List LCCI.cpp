class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        for (int i = 0; i < k; i++) {
            node2 = node2->next;
        }
        while (node2) {
            node1 = node1->next;
            node2 = node2->next;
        }
        return node1->val;
    }
};