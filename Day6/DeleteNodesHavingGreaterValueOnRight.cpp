class Solution
{
    public:
    Node* reverseList(Node* head) {
        if (!head || !head->next) {
            return head;
        }
        
        Node* rest = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return rest;
    }

    Node *compute(Node *head)
    {
        if (!head || !head->next) return head;
        head = reverseList(head);

        Node* maxNode = head;
        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->next->data < maxNode->data) {
                current->next = current->next->next;
            } else {
                current = current->next;
                maxNode = current;
            }
        }

        head = reverseList(head);

        return head;
    }
    
};