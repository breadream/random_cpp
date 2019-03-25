  string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        
        // table[i][j] -> substring from index i to j is palindrome or not
        bool table[s.size()][s.size()];
        memset(table, false, sizeof table);
        
        // each single character is consider as a palindrome
        for (int i = 0; i < s.size(); i++)
            table[i][i] = true;
        
        string res;
        int maxLen = 0;
        res = s[0]; // placeholder value
        
        // length 2 
        for (int i = 0; i < s.size()-1; i++)
            if (s[i] == s[i+1])
            {
                table[i][i+1] = true;
                res = s.substr(i, 2);
                maxLen = 2;   
            }
        
        int end; // end index of substring
        // length more than 2
        for (int subLen = 2; subLen < s.size(); subLen++)
        {
            for (int begin = 0; begin < s.size()-subLen; begin++)
            {
                end = begin + subLen;
                if (s[begin] == s[end] && table[begin+1][end-1])
                {
                    int tmpLen = end+1 - begin;
                    if (tmpLen > maxLen)
                    {
                        res = s.substr(begin, tmpLen);
                        maxLen = res.size();
                    }
                    table[begin][end] = true;
                }
            }
        }
        return res; 
    }
