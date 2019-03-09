#include <iostream>
#include <vector>

using namespace std;

/* Returns true if the there is a subarray of arr[] with sum equal to 'sum' 
otherwise returns false. Also, prints the result */
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

// Driver program to test above function 
int main() 
{ 
	vector<int> input = {15, 2, 4, 8, 9, 5, 10, 23}; 
	subArraySum(input, 23);
	return 0; 
} 

