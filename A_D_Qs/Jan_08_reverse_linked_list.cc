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
        stack<ListNode*> st;
        ListNode* dummyHead = new ListNode(-1); // dummyHead shouldn't be a nullptr
        ListNode* curr = head; // temporary node to contain current node
        while (curr)
        {
            st.push(curr);
            curr = curr->next ? curr->next : nullptr;
        }
        curr = dummyHead;
        while (curr && !st.empty())
        {
            curr->next = new ListNode(st.top()->val);
            st.pop();
            curr = curr->next ? curr->next : nullptr;
        }
        return dummyHead->next;
    }
};
