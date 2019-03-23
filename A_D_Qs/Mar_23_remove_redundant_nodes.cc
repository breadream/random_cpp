struct Node 
{
	int x, y;
	Node* next;
};


void removeNodes (Node* head)
{
	Node* curr = head;
	while (curr->next && curr->next->next)
	{
		Node* temp = curr->next->next;
		
		if (curr->x == curr->next->x && curr->x == temp->x)
		{
			free(curr->next);
			curr->next = temp;
		}

		else if (curr->y == curr->next->y && curr->y == temp->y)
		{
			free(curr->next;)
			curr->next = temp;
		}
		else
		{
			curr = curr->next;
		}
	}
}
