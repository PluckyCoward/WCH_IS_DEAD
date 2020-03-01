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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* last = head;
        int n = 1;
        for (n = 1; last->next != NULL; n++) {
            last = last->next;
        }
        last->next = head;
        ListNode* pst = head;
        for (int i = 0; i < n - k % n - 1; i++) {
            pst = pst->next;
        }
        head = pst->next;
        pst->next = NULL;
        return head;
    }
};