class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string originalCopy = s;
        int len = s.size();
        if (len < 1)
            return false;
        
        for (int subLen = 1; subLen <= len / 2; subLen++)
        {
            if (len % subLen == 0)
            {
                string shifted = shiftLeft (originalCopy, subLen);
                if (s == shifted)
                    return true;
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string s) {
        vector<int> table(s.size(), 0);
        for (int i = 1, j = 0; i < s.size(); i++)
        {
            while (j > 0 && s[i] != s[j])
                j = table[j-1];
            if (s[i] == s[j])
                table[i] = ++j;
        }
        int mark = table[s.size()-1];
        // table [s.size()-1] will have the most recently repeated substring index
        return mark != 0 && s.size() % (s.size() - mark) == 0;
    }
    
    string shiftLeft (const string & s, int len) 
    {
        // s = left + right
        string right = s.substr(len); // from index len to the end
        string left = s.substr(0, len); // left part of given string
        right += left;
        return right; // right + left
    }
};
