/* 
 * https://www.acmicpc.net/blog/view/21
 * Fenwick Tree; aka. Binary Indexed Tree
 * In order to implement Fenwick Tree, we need to know the last location of 1
 * when a number X becomes binary. 
 * e.g. 3 = 1'1' , 5 = 10'1', 12 = 1'1'10 
 * Let's say the value the last 1 represents L[i]
 * e.g. L[3] = 1, L[5] = 1, L[12] = 4
 * L[i] = i & -i
 * -(negative)num = ~(not)num + 1
 *  Tree[i] = The sum from A[i] to backward as much as L[i] (inclusive)
 * e.g. Tree[12] -> the sum from 12 to backward as much as L[12] (which is 4) 
 * 					A[12] + A[11] + A[10] + A[9]
 * 		Tree[7] -> from 7, L[7] (1) element to backward
 *
 * In order to find A[1] + ... + A[13]
 * A[1] + ... + A[13] = Tree[1101] + Tree[1100] + Tree[1000]
 * 1101 -> 1100 -> 1000,  the transition happens by removing the last 1 
 */

int sum(int i) {
	int ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
}

/* A[i] + ... + A[j] = (A[1] + ... + A[j]) - (A[1] + ... + A[i-1])
 * 					 = sum(j) - sum(i-1)
 */

/* After update some number, the section that includes the number
 * should be updated*/

void update(int i, int num)
{
	while (i <= n)
	{
		tree[i] += num;
		i += (i & -i);
	}
}
