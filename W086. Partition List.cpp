/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = new ListNode(-1);
        ListNode* r = new ListNode(-1);
        ListNode *p1=l,*p2=r;
        if (!head)
            return head;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
                head = head->next;
            }
        }
        p1->next = r->next;
        p2->next = NULL;
        return l->next;
    }
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        ListNode* sn = small;
        ListNode* ln = large;
        while(head) {
            if (head->val < x) {
                sn->next = head;
                sn = sn->next;
            }
            else {
                ln->next = head;
                ln = ln->next;
            }
            head = head->next;
        }
        ln->next = NULL;
        sn->next = large->next;
        return small->next;

    }
};