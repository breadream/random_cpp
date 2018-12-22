/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) 
            return;
        
        deque<ListNode*> dq;
        ListNode* ptr = head; // used for inserting nodes to deque
        
        while (ptr)
        {
            dq.push_back(ptr);
            ptr = ptr->next;
        }
        // remove 1st head, because we start from real head node
        dq.pop_front(); // if we don't remove it, head -> head ... 
        
        while (!dq.empty()) // interleave using read head ptr // in back and forth style  
        {
            head->next = dq.back(); 
            dq.pop_back();
            // move the head ptr    
            head = head->next;
            if (!dq.empty())
            {
                head->next = dq.front();
                dq.pop_front();
                head = head->next;
            }
        }
        head->next = nullptr;
    }
};
