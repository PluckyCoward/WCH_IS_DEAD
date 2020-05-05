class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* node = head;
        while(node != NULL) {
            ListNode* tmp = node->next;
            node->next = pre;
            pre = node;
            node = tmp;
        }
        return pre;
    }
};