#include <iostream>
#include <stack>

using namespace std;
// Data Structure to store a linked list node
struct Node
{
    int data;
    Node* next;
	Node (int val) : data(val), next(nullptr){}
};

// Helper function to push a new node at the beginning of the linked list
void push(Node* &head, int data)
{
    Node* newNode = new Node(data);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Helper function to print given linked list
void printList(const string &msg, Node* head)
{
    cout << msg << endl;
    while (head)
    {
		cout << head->data << endl;
        head = head->next;
    }
}

// Recursive function to add a given digit to the linked list
// representing a number.
int add(struct Node *head, int digit)
{
    // base case: end of the linked list is reached
    if (head == NULL)
        return digit;

    // store carry returned by the recursive call of the next node
    int carry = add(head->next, digit);

    // optimization: terminate the recursion if carry is 0 at any point
    if (carry == 0)
        return 0;

    // get sum of the current node and the carry
    int sum = head->data + carry;

    head->data = sum % 10;    // update value of the current node
    return sum/10;            // return carry
}

// Function to add a single-digit number to a singly linked list 
// whose nodes represents digits of a number
void addDigit(Node* &head, int digit)
{
    // Add given digit to the linked list using recursion
    int carry = add(head, digit);

    // if there is any carry left, add a new node at the beginning of the list
    if (carry) {
        push(head, carry);
    }
}

void addDigits (Node* &head, int target)
{
	Node* curr = head;
	Node* res = curr;
	stack<int> nums;
	int carry = 0;
	while (curr)
	{
		nums.push(curr->data);
		curr = curr->next;
	}
	curr = head;

	int LSB = nums.top() + target;
	nums.pop();;;;
	curr->next = new Node(LSB % 10);
	curr = curr->next;
	carry = LSB / 10;
	
	while (!nums.empty())
	{
		int digit = nums.top();
		nums.pop();
		curr->next = new Node((digit+carry) % 10);
		curr = curr->next;
		carry = (digit + carry) / 10;
	}

	if (carry)
	{
		curr->next = new Node(carry);
	}
	head = res->next;
}
// main function
int main(void)
{
    int number[] = { 9, 9, 9, 9, 3 };
    int n = sizeof(number)/ sizeof(int);

    Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
        push(head, number[i]);

    int digit = 7;

    //printList(" Original Linked List: ", head);
    //addDigit(head, digit);
    //printList("Resultant Linked List: ", head);

    printList(" Original Linked List: ", head);
    addDigits(head, digit);
    printList("Resultant Linked List: ", head);
    return 0;
}
