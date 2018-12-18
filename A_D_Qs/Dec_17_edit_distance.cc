class Solution {
public:
    // One crucial step here is that the "base case" starts off with the empty String.
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n * m == 0) // if either string is empty 
            return n+m;
        
        vector<vector<int>> table (n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i < n+1; i++)
            table[i][0] = i;
        for (int j = 1; j < m+1; j++)
            table[0][j] = j;
        
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < m+1; j++)
            {    
                // if each char of both words is same, use minimum prior solution  
                if (word1[i-1] == word2[j-1]) 
                    table[i][j] = table[i-1][j-1];
                else  // if not same, we need another edit for words. IE: add 1
				// So comparing "k" to "s", we first want to check 
				// what the minimum solution of the previous strings were 
				// (' ' vs ' ', ' ' vs 'k', ' ' vs 's' ). 
				// We see that the minimum prior solution is in the diagonal of our table.
                {
                    int left = table[i][j-1];
                    int up   = table[i-1][j];
                    int diag = table[i-1][j-1];
                    table[i][j] = 1 + min(left, min(up, diag));
                }
            }
        }
        return table[n][m];
    }
};
