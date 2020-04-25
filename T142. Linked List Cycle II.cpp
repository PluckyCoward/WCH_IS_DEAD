class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = fast->next;
        while(head != fast){
            head = head->next;
            fast = fast->next;
        }
        return fast;
    }
};