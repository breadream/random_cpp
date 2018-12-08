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
		if (head == nullptr || head->next == nextptr || k < 2)
			return nullptr;
		ListNode *dummy = new ListNode (-1);
		ListNode *prev = dummy, *tail = dummy, *temp;
		prev->next = head;
		while (true)
		{
			while (count > 0 && tail != nullptr)
			{
				tail = tail->next;
				count--;
			}
			if (tail == nullptr) // reach at an end of linkedlsit
				break;
			head = prev.next; // new head is located on next to the previous nodd 
			while (prev.next != tail)
			{
				temp = prev.next; // set temp node as next to the prev node
				prev->next = temp->next; // remove a temp node  
				temp->next = tail->next; // add a temp node next to the tail node
				tail->next = temp; // complete connecting a temp node with the tail node 
			}
			head = prev; // prev is your new head
			tail = prev; // prev is also your new tail
		}
		return dummy->next;
	}
};
		
