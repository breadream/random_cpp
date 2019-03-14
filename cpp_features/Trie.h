#pragma once 
#include <iostream>
using namespace std;

class Trie 
{
public:
	Trie() = default;
	~Trie();

	void insert(const string&);
	bool deletion(Trie*&, const string&) const;
	bool search(const string&);
	bool haveChildren(Trie const*) const;
private:
	enum {CHAR_SIZE = 128};
	bool isLeaf;
	Trie* character[CHAR_SIZE];
};
