/*
 * Cracking the coding interview edition 6
 * Problem 2-1 : Remove duplicates from an unsorted linked list.
 * Approach 1 : Naive approach of iterating and remove all further duplicates of current node.
 * 							Space complexity O(1) & time complexity O(n^2)
 * Approach 2: Use a hash table, space complexity O(n), time complexity O(n)
 */


#include <iostream>
#include <unordered_set>
#include <random>


struct Node {
	int data = 0;
	Node * next = nullptr;
};

/**
 * [insert a node at the head of list]
 * @param head [head of the list] // reference to pointer-to-node
 * @param data [new node's data]
 */
void insert( Node * & head, int data ) //  *& is used so that we can pass nullptr at the beginning 
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
	while( head ) {
		std::cout << head->data << "-->";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
}

//generate a random int between min and max
/**
 * [random_range helper routine to generate a random number between min and max (including)]
 * @param  min [min of range]
 * @param  max [max of range]
 * @return     [A random number between min and max]
 */
static inline int random_range(const int min, const int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}


// space complexity - O(n)
// time complexity - O(n)
/**
 * [removeDuplicates1 - Remove duplicates from the list using hash table]
 * @param head [head of list]
 */
void removeDuplicates1( Node * head ) {
	if (!head || !head->next) return;

	std::unordered_set<int> set;
	Node * prev = head;
	Node * curr = head->next;
	set.insert(head->data);
	while(curr) 
	{
		// while curr is valid and its data is already in the set
		// we skip those nodes 
		while (curr && set.count(curr->data)) 
			curr = curr->next;
		prev->next = curr;
		prev = curr;
		if (curr) 
		{
			set.insert(curr->data);
			curr = curr->next;
		}
	}
}


int main() {
	Node * head1 = nullptr;
		insert(head1, random_range(1,8));
	printList(head1);
	removeDuplicates1(head1);
	printList(head1);
	return 0;
}
