#include "Trie.h"
#include <iostream>

using namespace std; 

Trie::~Trie() 
{
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		delete character[i];
		character[i] = nullptr;
	}
}

// Iterative function to insert a key in the Trie
void Trie::insert(const string& key)
{
	// start from root node
	Trie* curr = this;

	for (int i = 0; i < key.size(); i++)
	{
		// create a new node if path doesn't exists
		if (curr->character[key[i]] == nullptr)
			curr->character[key[i]] = new Trie();

		// go to next node
		curr = curr->character[key[i]];
	}

	// mark current node as leaf
	curr->isLeaf = true;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::search(const string& key) 
{
	// return false if Trie is empty
	if (this == nullptr)
		return false;

	Trie* curr = this;
	for (int i = 0; i < key.size(); i++)
	{
		// go to next node
		curr = curr->character[key[i]];

		// reached end of path in Trie before it finds the whole characters in key
		if (curr == nullptr)
			return false;
	}

	// if current node is a leaf 
	// and we have reached the end of the string 
	return curr->isLeaf;
}

// returns true if given node has any children
bool Trie::haveChildren(Trie const* curr) const
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])
			return true;	// child found

	return false;
}

// Recursive function to delete a key in the Trie
bool Trie::deletion(Trie*& curr, const string& key) const
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

	// if we have not reached the end of the key
	if (key.size())
	{
		// recurse for the node corresponding to next character in the key
		// and if it returns true, delete current node (if it is non-leaf)
		if (curr != nullptr 
			&& curr->character[key[0]] != nullptr 
			&& deletion(curr->character[key[0]], key.substr(1)) // substr(1) -> from 1 to the end 
			&& curr->isLeaf == false)
		{
			if (!haveChildren(curr))
			{
				delete curr;
				curr = nullptr;
				return true;
			}
			else 
			{
				return false;
			}
		}
	}

	// if we have reached the end of the key
	if (key.size() == 0 && curr->isLeaf)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(curr))
		{
			// delete current node
			delete curr;
			curr = nullptr;

			// delete non-leaf parent nodes
			return true;
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			curr->isLeaf = false;

			// don't delete its parent nodes
			return false;
		}
	}

	return false;
}

// C++ implementation of Trie Data Structure - Insertion, Searching and Deletion
int main()
{
	Trie* head = new Trie();

	head->insert("hello");
	std::cout << head->search("hello") << " ";		// print 1

	head->insert("helloworld");
	std::cout << head->search("helloworld") << " "; // print 1

	std::cout << head->search("helll") << " ";		// print 0 (Not found)

	head->insert("hell");
	std::cout << head->search("hell") << " ";		// print 1

	head->insert("h");
	std::cout << head->search("h");					// print 1

	std::cout << std::endl;

	head->deletion(head, "hello");
	std::cout << head->search("hello") << " ";		// print 0 ("hello" deleted)
	std::cout << head->search("helloworld") << " ";	// print 1
	std::cout << head->search("hell");				// print 1

	std::cout << std::endl;

	head->deletion(head, "h");
	std::cout << head->search("h") << " ";			// print 0 ("h" deleted)
	std::cout << head->search("hell") << " ";		// print 1
	std::cout << head->search("helloworld");		 // print 1

	std::cout << std::endl;

	head->deletion(head, "helloworld");
	std::cout << head->search("helloworld") << " ";	// print 0 ("helloworld" deleted)
	std::cout << head->search("hell") << " ";		// print 1

	head->deletion(head, "hell");
	std::cout << head->search("hell");				// print 0

	std::cout << std::endl;

	if (head == nullptr)
		std::cout << "Trie empty!!\n";				// Trie is empty now

	std::cout << head->search("hell");				// print 0

	return 0;
}
