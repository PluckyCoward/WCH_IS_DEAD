//dfs
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) 
            return NULL;
        Node* node = head;
        while (node) {
            Node* nextNode = node->next;
            if (node->child) {
                Node* childHead = node->child;
                node->next = childHead;
                childHead->prev = node;
                node->child = NULL;
                Node* childTail = childHead;
                while (childTail && childTail->next) {
                    childTail = childTail->next;
                }
                childTail->next = nextNode;
                if (nextNode)
                    nextNode->prev = childTail;
            }
            node = node->next;
        }
        return head;
    }
};