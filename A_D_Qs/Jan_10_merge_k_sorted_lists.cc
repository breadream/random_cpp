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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, std::greater<int>> pq; // default pq gets the largest, std::greater to get the smallest 
        for (auto listNode : lists)
            while (listNode)
            {
                pq.push(listNode->val);
                listNode = listNode->next ? listNode->next : nullptr;
            }
        
        // it's always a good idea to start with a dummyHead 
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        // O(N * log(k)); N = number of nodes in final linked list, k = number of linked lists
        while (!pq.empty())
        {
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next ? curr->next : curr;
        }
        return dummyHead->next;
    }
};
