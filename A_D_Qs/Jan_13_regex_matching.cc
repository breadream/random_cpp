class Solution {
public:
    bool isMatch(string s, string p) {
        // check[i][j]; i = text index, j = pattern index 
        // if it is true, i-th value of text and j-th value of regex match 
        vector<vector<bool>> check (s.length()+1, vector<bool>(p.length()+1, false)); // start from index 1 
        check[0][0] = true;
        // Pattern like these a* , a*b*, a*b*c*
        for (int j = 1; j < p.length()+1; j++)
            if (p[j-1] == '*')
                check[0][j] = check[0][j-2];
        
        
        for (int i = 1; i < s.length()+1; i++)
        {
            for (int j = 1; j < p.length()+1; j++)
            {
                // if character matches with pattern or pattern is 
                if (p[j-1] == s[i-1] || p[j-1] == '.')
                    check[i][j] = check[i-1][j-1];
                else if (p[j-1] == '*')
                {
                    check[i][j] = check[i][j-2];
                    if (p[j-2] == '.' || p[j-2] == s[i-1])
                        check[i][j] = check[i][j] || check[i-1][j];
                }
                else 
                    check[i][j] = false;
            }
        }
        
        return check[s.length()][p.length()];
    }
};
