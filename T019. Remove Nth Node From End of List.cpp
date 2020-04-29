class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = new ListNode(0);
        p1->next = head;
        ListNode *p2 = head;
        ListNode *res = p1;
        while(n--)
            p2 = p2->next;
        while(p2!=NULL){
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next = p1->next->next;
        return res->next;
    }
};