#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to print given set
void printSet(vector<int> const &set)
{
	for (const int j : set)
		cout << setw(2) << j;
	cout << endl;
}

// Function to generate power set of given set S
void findPowerSet(const vector<int> &S, vector<int> &set, int n)
{
	// if we have considered all elements
	if (n == 0)
	{
		printSet(set);
		return;
	}

	// consider current element 
	set.emplace_back(S[n-1]);
	findPowerSet(S, set, n-1);

	// OR just don't consider current element 
	set.pop_back();
	findPowerSet(S, set, n-1);
}

void findPowerSet(const vector<int>& S, int n)
{
	// N = total number of subsets
	int N = pow (2, n);
	
	for (int i = 0; i < N; i++)
	{
		// check each bit in N 
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
				cout << S[j] << " ";
		}
		cout << endl; 
	}
}


// main function
int main()
{
	vector<int> S = { 1, 2, 3 };
	int n = S.size();

	vector<int> set;

	findPowerSet(S, set, n);
	findPowerSet(S, n);

	return 0;
}
