/**
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
        RandomListNode *curr = head, *curr_copy = nullptr, *res = nullptr;
        if (!curr)
            return nullptr;
        
        // make a copy of each node and append it its original node     
        // 1 -> 2 -> 3 -> 4 ...  1 -> 1' -> 2 -> 2' -> 3 -> 3' -> 4 -> 4'
        while (curr)
        {
            curr_copy = new RandomListNode(curr->label); // make a node
            curr_copy->next = curr->next; // the next of copied node is current node's next
            curr->next = curr_copy; // create a link between current and its copy
            curr = curr_copy->next; // set the next original node as current nocde
        }
        
        curr = head; // reset the current node as head
        // create a link to random node using the original nodes' random  
        while (curr)
        {
            curr_copy = curr->next; // point to 1' instead of 1
            if (curr->random) // check if random pointer of original node is valid
                curr_copy->random = curr->random->next; /* caution */ // it's next of random pointer instead of random itself
            curr = curr_copy->next;
        }
        
        curr = head;
        res = head->next; 
        while (curr)
        {
            curr_copy = curr->next; // 1'
            curr->next = curr_copy->next; // connect to 'original' next node
            curr = curr->next; // advance pointer to the next node
            if (curr)
                curr_copy->next = curr->next; // connect copied nodes
        }
        
        return res;
    }
       
};
