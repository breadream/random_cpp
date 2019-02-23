int32_t insert(int32_t N, int32_t M, int i, int j) 
{
	/* Create a mask to clear bits i ~ j in N, 
	 * if the number is 11111111 and i = 2, j = 5
	 * Result should be 11000011*/
	int ons = ~0;

	// before j 
	int front = ones << (j+1);
	// after i
	int back = ((1 << (i)) - 1);

	int mask = front | back;

	/* Clear bits j through i then put M in N */
	int newN = N & mask;
	int newM = M << i;

	return newN | newM;
}
