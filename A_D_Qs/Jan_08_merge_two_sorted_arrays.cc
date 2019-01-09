class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if (!l1 || !l2)
            return l1 ? l1 : l2;
        
        ListNode *dummyHead = new ListNode(-1); // result node
        ListNode *curr = dummyHead; // current node
        
        while (l1 && l2) // valid 
        {
            if (l1->val <= l2->val)
            {
                curr->next = new ListNode(l1->val);
                l1 = l1->next ? l1->next : nullptr;
            }
            else // l1->val > l2->val
            {
                curr->next = new ListNode(l2->val);
                l2 = l2->next ? l2->next : nullptr;
            }
            curr = curr->next;
        }
        
        if (l1 || l2) // check remaining nodes in either of list 
            curr->next = l1 ? l1 : l2;
        
        return dummyHead->next; 
    }
};
