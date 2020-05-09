class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* node = dummy;
        while (node->next != NULL) {
            if (node->next->val == val) {
                ListNode* tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            }
            else 
                node = node->next;
            
        }
        return dummy->next;
    }
};