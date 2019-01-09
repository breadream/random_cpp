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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr, *prev, *next; 
        curr = head;
        prev = nullptr;
        while (curr)
        {
            next = curr->next; // save the next node's address
            curr->next = prev; // make a link to previous node
            prev = curr; // previous node now points to current node
            curr = next; // move the current node to next node
        }
        head = prev; // new list starts from previous node
        return head;
    }
};
