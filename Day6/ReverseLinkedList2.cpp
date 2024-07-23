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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* Left = dummy;
        ListNode* curr = head;

        for(int i=1; i<left; i++){
            Left = Left->next;
            curr = curr->next;
        }

        ListNode* newhead = curr;
        ListNode* prev = nullptr;
        
        for(int i=0; i<right-left+1; i++){
            ListNode* Nnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr= Nnode;
        }
        Left->next = prev;
        newhead->next = curr;

        return dummy->next;
    }
};