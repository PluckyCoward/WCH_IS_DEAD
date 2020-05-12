class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* Evenhead = node2;
        while (node2 && node2->next) {
            node1->next = node2->next;
            node2->next = node2->next->next;
            node1 = node1->next;
            node2 = node2->next;
        }
        node1->next = Evenhead;
        return head;
    }
};