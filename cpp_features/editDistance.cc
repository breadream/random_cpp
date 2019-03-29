/* Edit distance algorithm determines the similarity between two strings
 * The degree of similarity is defind by the number of insertion, deletion and modification are made
 * e.g. MI , NCS 
 * -> left diagonal up is the edit distance of comparing M and NC ; cost to substitute 
 * -> top  is for comparing M and NCS; cost to delete 
 * -> left is for comparing MI and NC; cost to add
 *
 * if A[i] == B[j], D(i, j) = D(i-1, j-1) 
 * else if A[i] != B[j], D(i, j) = min (D(i-1,j)+1, D(i,j-1)+1, D(i-1,j-1)+1)
 * */


const int BUFFER = 1000;
int dist[BUFFER][BUFFER];
int levenshtein(const string& str1, const string& str2)
{
	for (int i = 1; i <= str1.size(); i++)
		dist[i][0] = i;
	for (int j = 1; j <= str2.size(); j++)
		dist[0][j] = j;

	for (int j = 1; j <= str2.size(); j++)
	{
		for (int i = 1; i <= input1.size(); i++)
		{
			if (str[i-1] == str2[j-1])
				dist[i][j] = dist[i-1][j-1];
			else
				dist[i][j] = min(dist[i-1][j-1]+1, 
						         dist[i  ][j-1]+1,
								 dist[i-1][j  ]+1);
		}
	}

	return dist[str1.size()][str2.size()];
}
