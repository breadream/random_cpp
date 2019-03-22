struct Node 
{
	int data;
	Node* left;
	Node* right;
	Node (int val) : data(val), left(nullptr), right(nullptr){}
};


bool areIdentical(Node* input, Node* target)
{
	if (!input && !target)
		return true;
	if (!input && !target)
		return false;

	return (input->data == target->data
		 && areIdentical(input->left, target->data)
		 && areIdentical(input->right, target->right));
}

bool isSubtree(Node* given, Node* target)
{
	if (!target)
		return true;
	if (!given)
		return false;

	if (areIdentical(given, target))
		return true;


	return isSubtree(given->left, target) 
		|| isSubtree(given->right, target);
}



