/*
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur = head, *cur_clone = nullptr, *head_clone= nullptr;
    
        if (!cur)
            return nullptr;     
        
        while (cur != nullptr)
        {
            cur_clone = new RandomListNode(cur->label); 
            cur_clone->next = cur->next;
            cur->next = cur_clone;
            cur = cur_clone->next;
        }
        
        cur = head;
        while (cur != nullptr)
        {
            cur_clone =cur->next;
            if (cur->random)
                cur_clone->random = cur->random->next;
            cur = cur_clone->next;
        }
        
        
        cur = head;
        head_clone = head->next;
        
        while (cur != nullptr)
        {
            cur_clone = cur->next;
            cur->next = cur_clone->next;
            cur = cur->next;
            if (cur)
                cur_clone->next = cur->next;
        }
        return head_clone;
    }
       
};
