class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* node = head;
        int a = 0;
        while (l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = a + x + y;
            a = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (a > 0)
            node->next = new ListNode(a);
        return head->next;
    }
};