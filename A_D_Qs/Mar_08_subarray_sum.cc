#include <iostream>
#include <vector>

using namespace std;

void subArraySum(const vector<int>& arr, int sum) 
{ 
	int n = arr.size();
	int currSum;
	for (int start = 0; start < n; start++)
	{
		currSum = arr[start];
		for (int end = start+1; end <= n; end++)
		{
			if (currSum == sum)
			{
				cout << "Answer: starting from " <<  start << " and end with " << end-1 << endl;
				return;
			}
			if (currSum > sum || end == n)
				break;
			currSum += arr[end];
		}
	}
} 

void subArraySum2(const vector<int>& arr, int sum) 
{ 
	int currSum = arr[0];
	int start = 0; 
	for (int end = 1; end <= arr.size(); end++)
	{
		// if the current sum is greater than target sum, subtract the leading arrays
		while (currSum > sum && start < end-1)
		{
			currSum -= arr[start];
			start++; // move the start ptr to right side
		}
		if (currSum == sum)
		{
			cout << "Answer: starting from " <<  start << " and end with " << end-1 << endl;
			return;
		}

		if (end < arr.size())
			currSum += arr[end];
	}
} 

// Driver program to test above function 
int main() 
{ 
	vector<int> input = {15, 2, 4, 8, 9, 5, 10, 23}; 
	subArraySum(input, 23);
	subArraySum2(input, 23);
	return 0; 
} 

