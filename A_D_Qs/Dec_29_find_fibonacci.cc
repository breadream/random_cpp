// Compute the nth Fibonacci number recursively. 
// Optimized by caching subproblem results
int fib(int n)
{
	if (n < 2) return n;
	int cache[n+1];
	memset(cache, -1, sizeof(cache));
	cache[0] = 0;
	cache[1] = 1;
	return fib(n, cache);
}
int fib(int n, int cache[])
{
	if (cache[n] >= 0)
		return cache[n];
	// Compute and add to cache before returning
	cache[n] = fib(n-1, cache) + fib(n-2, cache);
	return cache[n];
}

// iteratively; bottom up approach
int fib(int n) 
{
	if (n == 0)
		return 0;

	int cache[n+1];
	cache[1] = 1;

	for (int i = 2; i <= n; i++)
		cache[i] = cache[i-1] + cache[i-2];

	return cache[n];
}

// Compute the nth Fibonacci number iteratively 
// with constant space. We only need to save 
// the two most recently computed values
int fib(int n)
{
	if (n < 2) 
		return n;
	int n1 = 1, n2 = 0;
	for (int i = 2; i <= n; i++)
	{
		int tempSum = n1 + n2;
		n2 = n1;
		n1 = tempSum;
	}
	return n1 + n2;
}

