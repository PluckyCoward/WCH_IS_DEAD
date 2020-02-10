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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy;
        ListNode* p2;
        while (p1->next != NULL && p1->next->next != NULL) {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1 = p2;
        }
        return dummy->next;
    }
};