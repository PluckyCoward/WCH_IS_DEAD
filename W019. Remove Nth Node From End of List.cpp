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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for (int i = 0; i < n + 1; i++) {
            q = q->next;
        }
        
        while (q) {
            p = p->next;
            q = q->next;
        }
        
        ListNode* del = p->next;
        p->next = del->next;
        delete del;
        
        ListNode* res = dummy->next;
        delete dummy;
        
        return res;
    }
};

//No dummy node
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        return head;
    }
};