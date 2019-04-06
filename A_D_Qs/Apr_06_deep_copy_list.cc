Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        Node* currCopy = nullptr;
        Node* res = nullptr;
            
        // 1->2->3->4-> ... ==> 1->1'->2->2'->3->3'->4->4'->...
        while (curr)
        {
            currCopy = new Node(curr->val, curr->next, nullptr);
            curr->next = currCopy; // connect the original node with copied node
            curr = currCopy->next;
        }
        
        // reset the current pointer 
        curr = head;
        
        // 1->1'->2->2'
        while (curr)
        {
            currCopy = curr->next; // 1'
            if (curr->random)  
                currCopy->random = curr->random->next; // should point to copied one 
            curr = currCopy->next;
        }
        
        curr = head;
        res = head->next; // pointing to 1' 
        
        // 1->1'->2->2'
        // 1'->2'
        while (curr)
        {
            currCopy = curr->next; // pointing 1'
            curr->next = currCopy->next; // 1->2
            curr = curr->next; // 2
            if (curr)
                currCopy->next = curr->next; // 1'->2'
        }
        return res;
    }
