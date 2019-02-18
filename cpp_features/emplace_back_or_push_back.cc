#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Test
{
private:
	int numMember;
	string strMember;
public:
	Test()
	{
		cout << "Default Constructor..." << endl;
	}

	Test(int n, string str) 
	:numMember(n), strMember(str)
	{
		cout << strMember << " constructor with a parameter" << endl;
	}

	Test (Test& right) 
	:numMember(right.numMember), strMember(right.strMember)
	{
		cout << "copy constructor" << endl;
	}

	Test (Test&& right) 
	:numMember(right.numMember), strMember(right.strMember)
	{
		cout << strMember << "Move constructor" << endl;
	}
	
	~Test()
	{
		cout << strMember << " destructor" << endl;
	}

};

int main()
{
	std::vector<Test> vecTest1;
	std::vector<Test> vecTest2;
	// the constructor and destructor are called twice 
	// because push_back() needs an object of a class as a parameter
	vecTest1.push_back(Test(1, "Test1")); 
	/* String Opearation 
	 * new string object implicitly created initialized with provided char* 
	 * push_back is called and will copy this string into the vector using the move constructor
	 * because the original string is a temporary object, then temporary object will be destroyed */


	cout << "--------------------" << endl;
	// emplace_back() finds the only constructor that can receive '2, "Test2"'
	// it's more efficient because the constructor and destructor are called once
	// because the compiler creates and add an object without copying or moving an object
	vecTest2.emplace_back(2, "Test2"); 
	/* String Operation
	 * emplace_back(s) constructrs a string in-place w/o creating a temporary string 
	 * emplace_back will be called directly with char* argument 
	 * and then create a string to be stored in the vector initialized with this char* 
	 * -> we can avoid constructing and destroying an unnecessary temporary string object */
	
	return EXIT_SUCCESS;
}
