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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = new ListNode(-1);
        ListNode* res = curr;
        ListNode* tracker = head; // the node tracking if the traversing ends before it reaches k
        bool preEnd = false; // a friend of tracker above, it tells whether it pre-ended or not 
        curr->next = head;
        stack<ListNode*> st;
        while (head)
        {
            while (st.size() < k && head)
            {
                ListNode* temp = new ListNode(head->val);
                st.push(temp);
                head = head->next; 
            }
            if (st.size() < k)
            {
                preEnd = true;
                break;
            }
            while (!st.empty())
            {
                curr->next = st.top();
                st.pop();
                curr = curr->next;
            }
            tracker = head;
        }
        curr->next = preEnd ? tracker : curr->next; // check pre-ending 
        return dummy->next;
    }
};
