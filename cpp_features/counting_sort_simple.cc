#include <iostream>
using namespace std;

int k = 0;
// A; array to be sorted, B; sorted array to return, n; size of array 
void countingSort (int input[], int output[], int n)
{
	int count[k];
	for (int i = 0; i < k+1; i++) // initialize array as zeros  
		count[i] = 0;

	for (int j = 1; j <= n; j++) // Count the number of times each value occurs in the input
		count[input[j]]++;

	for (int i = 1; i <= k; i++) // make sum cumulative 
		count[i] += count[i-1];

	// Transfer numbers from input to output array at locations provided by counting array 
	for (int j = n; j >= 1; j--)
	{
		output[count[input[j]]] = input[j]; // place the elements at its index
		count[input[j]]--;
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;
	
	/*A stores the elements input by user */
	/*B stores the sorted sequence of elements*/  	
	int A[n],B[n]; 
	
	for(int i=1;i<=n;i++)        
	{
		cin>>A[i];
		if(A[i]>k)
		{
			/*It will modify k if an element 
			occurs whose value is greater than k*/
			k=A[i];              
		}
	}
	countingSort(A,B,n);        
	/*It will print the sorted sequence on the 
	console*/ 
	for(int i=1;i<=n;i++)       
	{
		cout<<B[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}
