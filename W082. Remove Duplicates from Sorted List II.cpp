//Recursion
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next != NULL && head->val == head->next->val) {
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }
        else
            head->next = deleteDuplicates(head->next);
        return head;
    }
};
//Normal
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;

        ListNode* cur = preHead;
        int delVal;
        while(cur->next != NULL){
            if (cur->next->next != NULL && cur->next->val == cur->next->next->val) {
                delVal = cur->next->val;
                while(cur->next != NULL && cur->next->val == delVal){
                    ListNode* delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                }
            } else {
                cur = cur->next;
            }
        }
        ListNode* newHead = preHead->next;
        delete preHead;
        return newHead;
    }
};