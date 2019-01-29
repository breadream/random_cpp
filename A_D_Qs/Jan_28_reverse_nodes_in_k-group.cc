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
        if (head == nullptr || head->next == nullptr || k < 2)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *temp, *tail = dummy;
        
        while (true)
        {
            int count = k;
            while (count > 0 && tail != nullptr)
            {
                tail = tail->next;
                --count;
            }
            if (tail == nullptr) // reach an end of linked list 
                break;
            
            head = prev->next; // return the head back to next to previous node 
            while(prev->next != tail)
            {
                temp = prev->next; // set temp next to prev
                prev->next = temp->next; // delete temp from current place
                temp->next = tail->next; // add temp next to tail 
                tail->next = temp; // complete adding temp
            }
            // move pointers next to tail in order to start from tail index 
            tail = head;
            prev = head;
        }
        return dummy->next;
    }
};
