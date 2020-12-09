class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 != NULL) {
            if (p2->val == p1->val) {
                p2 = p2->next;
                delete(p1->next);
                p1->next = p2;
            }
            else {
                p1 = p2;
                p2 = p2->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p != NULL && p->next != NULL) {
            if (p->val == p->next->val) 
                p->next = p->next->next;
            else 
                p = p->next;
        }
        return head;
    }
};