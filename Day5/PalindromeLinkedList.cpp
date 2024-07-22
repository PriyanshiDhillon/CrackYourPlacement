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
    bool isPalindrome(ListNode* head) {
        if(head->next== nullptr) return true;
        stack<int> Elements;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            Elements.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast != nullptr && fast->next == nullptr) slow=slow->next;
        while(slow!=nullptr){
            if(slow->val == Elements.top()){
                Elements.pop();
                slow =slow->next;
            }
            else return false;
        }
        return true;
    }
};