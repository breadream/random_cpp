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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1); // temporary head to the result list node 
        ListNode* curr = dummyHead; // current 
        int carry = 0;
        while (l1 || l2 || carry) // carry -> check the most significant digit 
        {
            int sum = (l1 ? l1->val : 0) +  (l2 ? l2->val : 0)  + carry;
            curr->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            curr = curr->next;
        }
        
        return dummyHead->next;
    }
};
