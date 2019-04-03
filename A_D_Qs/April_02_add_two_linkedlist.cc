ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(-1);
	ListNode* curr = dummyHead;
	int carry = 0;
	while (l1 || l2 || carry)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		curr->next = new ListNode(sum % 10);
		carry = sum / 10;
		l1 = l1 ? l1->next : nullptr;
		l2 = l2 ? l2->next : nullptr;
		curr = curr->next;
	}
	
	return dummyHead->next;
}
