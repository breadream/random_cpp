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
	cout << "--------------------" << endl;
	// emplace_back() finds the only constructor that can receive '2, "Test2"'
	// it's more efficient because the constructor and destructor are called once
	// because the compiler creates and add an object without copying or moving an object
	vecTest2.emplace_back(2, "Test2"); 
	
	return EXIT_SUCCESS;
}
