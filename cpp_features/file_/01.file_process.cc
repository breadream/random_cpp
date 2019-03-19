#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream fin; 
	ofstream fout;
	fout.open("test?.txt");
	fin.open("test.txt");
	string line;


	while (!fin.eof())
	{
		getline(fin, line);
		fout << line << endl;
	}
	fout.close();
	fin.close(); 
	return 0;
}

