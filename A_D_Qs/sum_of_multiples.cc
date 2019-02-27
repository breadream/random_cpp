#include <iostream>
#include <cmath>

using namespace std;

// sum of arithmetic sequence (1 to n) = 0.5 * n * (n+1)
int makeSum (int num)
{
	return 0.5 * num * (num+1);
}

int main()
{
	size_t sum = 0;
	const int K = 1000;
	/* we need to subtract 1 from 1000 because 1000 is exclusive (*less than 1000)
	 * and divide it by 3, 5 and 15 to count the number of each multiples */
	int sumOfThree = 3 * makeSum(floor((K-1) / 3));
	int sumOfFive = 5 * makeSum(floor((K-1) / 5));
	int sumOfFifteen = 15 * makeSum(floor((K-1) / 15));
	// we need to exclude the intersection of 3 and 5 which is 15
	cout << "Sum of all multiples of 3 or 5 less than 1000 is " << 
		 sumOfThree + sumOfFive - sumOfFifteen << endl;
	return 0;
} 
