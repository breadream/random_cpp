#include <iostream>

using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	// prime number shouldn't be a multiple of n
	// set the limit on a divisor as sqrt (n) 
	for (int i = 2; i*i <= n; i++)
	{
		if (!prime[i]) // if it is false already, skip it
			continue;
		else if (prime[i])
			for (int j = i*i; j <= n; j += i) // update all the multiples of n to be false
				prime[j] = false;;
	}

	for (int i = 2; i <= n; i++)
		if (prime[i])
			cout << i << " ";
}

// Driver Program to test above function 
int main() 
{ 
    int n = 100; 
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl; 
    SieveOfEratosthenes(n); 
    return 0; 
} 
