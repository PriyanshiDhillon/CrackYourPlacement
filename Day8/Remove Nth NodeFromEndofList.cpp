/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || n <= 0) 
        return nullptr;

    head = reverse(head); 

    ListNode* temp = head;
    ListNode* prev = nullptr;
    for (int i = 1; i < n && temp != nullptr; ++i) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return reverse(head); 
    }

    if (prev != nullptr) {
        prev->next = temp->next;
    } else {
        head = temp->next;
    }
    delete temp;

    return reverse(head);
    }
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front= head->next;
        front->next = head;
        head->next = nullptr; 
        return newHead;
    }
};