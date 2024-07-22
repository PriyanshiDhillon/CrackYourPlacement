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
    int getDecimalValue(ListNode* head) {
        vector<int> num;
        int ans = 0;
        ListNode* temp = head;
        while (temp != nullptr) { 
            num.push_back(temp->val);
            temp = temp->next;
        }
        int n = num.size()xa;
        for (int i = 0; i < n; ++i) {
            if (num[n - i - 1] == 1) {
                ans += pow(2, i);
            }
        }
        return ans;
    }
};