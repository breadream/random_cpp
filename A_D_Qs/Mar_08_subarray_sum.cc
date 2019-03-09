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

/* if the arr is     {5, 10, 2, -2, -20, 10} and want to find sum of -10
 * cumulative sum is {5, 15, 17, 15, -5, 5}  
 * [10, 0] 
 * [12, 1]
 * []
 * */
void subArraySum (const vector<int>& arr, int sum)
{
	unordered_map<int, int> map; // K, V = [currSum-sum, index]
	int currSum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		currSum += arr[i];
		// sum of index 0 to i (inclusive) is equal to sum
		if (currSum == sum)
		{
			cout << "Sum found between indexes " << 0 << " to " << i << endl; 
            return; 
		}
		// if it is already in map,
		// the subarray whose sum is the same value as target sum exists
		if (map.count(currSum-sum))
		{
		     cout << "Sum found between indexes " << map[curr_sum - sum] + 1
			      << " to " << i << endl;
             return;
		}
		map[currSum] = i;
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

