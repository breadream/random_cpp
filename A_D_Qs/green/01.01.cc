
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

bool isUniqueChars (const string & str)
{
	// let's assume we use ASCII string 
	if (str.length() > 128)
		return false;
		
	vector<bool> set(128);
	for (auto & c : str)
	{
		if (set[int(c)])
			return false;
		set[int(c)] = true;
	}

	return true;
}

// boolean usually occupies 8 bits, why not only one bit? 
// because every C++ data type must be addressable 
bool isUniqueChars_bitset (const string & str)
{
	std::bitset<256> bits(0); // extended ASCII characters  
	for (auto & c : str)
	{
		/* bool test (size_t pos) const; 
		 * bit at pos is set or not */ 
		if (bits.test(int(c)) > 0 ) 
			return false;
		bits.set(int(c));
	}
	return true;
}


int main()
{
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto & word : words)
			cout << word << std::string(": ") << boolalpha << isUniqueChars(word) <<endl;

		for (auto & word : words)
			cout << word << std::string(": ") << boolalpha << isUniqueChars_bitset(word) <<endl;
		return 0;
}
