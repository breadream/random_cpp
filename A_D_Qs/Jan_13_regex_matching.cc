class Solution {
public:
    bool isMatch(string s, string p) {
        // check[i][j]; i = text index, j = pattern index 
        // if it is true, i-th value of text and j-th value of regex match 
        vector<vector<bool>> check (s.length()+1, vector<bool>(p.length()+1, false)); // both start from index 1 
        
        // empty string matches empty string pattern
        check[0][0] = true; 
        // Patterns like a* , a*b*, a*b*c*; empty string possible
        // 0th row of the table 
        
        for (int i = 1; i < p.length()+1; i++)
            if (p[i-1] == '*')
                check[0][i] = check[0][i-2]; // look up the 2 steps left value; zero occurrence 
        
        for (int i = 1; i < s.length()+1; i++)
        {
            for (int j = 1; j < p.length()+1; j++)
            {
                // if a character matches a pattern or the pattern is '.'
                if (p[j-1] == s[i-1] || p[j-1] == '.') // '.' can be any character
                    check[i][j] = check[i-1][j-1];
                /* crucial part */
                else if (p[j-1] == '*')
                {   //zero occurrence of previous pattern, assume there's no regex pattern
                    check[i][j] = check[i][j-2]; // 2 steps left previous table; 
                    
                    // one or more occurrences of previous pattern
                    // check if the previous pattern matches the input string 
                    // or the pattern is '.'(any character)
                    if (p[j-2] == s[i-1] || p[j-2] == '.')
                        //    x a *  ======> 
                        //  x        ======> only consider these two rows = check[i-1][j] (upper row value)
                        //  a     c  -> (c = current) since a is part of a*, it can be omitted.       
                        check[i][j] = check[i][j] | check[i-1][j]; // previous input character is part of regex pattern
                }
                else
                    check[i][j] = false;
            }
        }
        return check[s.length()][p.length()];
    }
};
