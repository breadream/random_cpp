class Solution {
public:
    string longestPalindrome(string s) {
        // if the string less than or equal to 1, just return it 
        if (s.length() <= 1)
            return s;
        
        // table[i][j] = if the string from index i to j is palindrome or not
        vector<vector<bool>> table (s.length(), vector<bool> (s.length(), false));
        
        string palindrome;
        int longest;
        
        // palindrome length = 1 
        for (int i = 0; i < s.length(); i++)
            table[i][i] = true;
        palindrome = s[0]; // placeholder value 
        longest = 1;
        
        // palindrome length = 2
        for (int i = 0; i < s.length()-1; i++)
            if (s[i] == s[i+1])
            {
                table[i][i+1] = true;
                palindrome = s.substr(i, 2);
                longest = palindrome.length();
            }
        
        // palindrome length greater than 2
        int j; // end index
        for (int k = 2; k < s.length(); k++) // the size of substring 
        {
            for (int i = 0; i < s.length()-k; i++) // the start index of substring 
            {
                j = i + k;
                if (s[i] == s[j] && table[i+1][j-1]) // palindrome check by looking up the table (within substring)
                {
                    if (j+1 - i > longest) // check the larger substring
                    {
                        palindrome = s.substr(i, j+1 - i);
                        longest = palindrome.length();
                    }
                    table[i][j] = true;
                }
            }
        }
        return palindrome;
    }
};
