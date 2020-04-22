class MyLinkedList {
public:
    ListNode* head;
    int count;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode();
        count = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= count)
            return -1;
        int x = 0;
        ListNode* first = head->next;
        while(x++ != index){
            first = first->next;
        }
        return first->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* pre = new ListNode(val);
        pre->next = head->next;
        head->next = pre;
        count++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* last = new ListNode(val);
        ListNode* first = head->next;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = last;
        count++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* cur = new ListNode(val);
        ListNode* first = head;
        int length = -1;
        while(length < index - 1){
            first = first->next;
            length++;
        }
        cur->next = first->next;
        first->next = cur;
        count++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* first = head;
        int length = -1;      
        if(index >= count){
            return;
        }
        while(first != NULL)
        {
            if(length == index - 1)
                break;
            first = first->next;
            length++;
        }
        ListNode* node = first->next;
        first->next = node->next;
        count--;
        delete(node);
    }
};
