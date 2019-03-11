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
    
    string shiftLeft (const string & s, int len) 
    {
        // s = left + right
        string right = s.substr(len); // from index len to the end
        string left = s.substr(0, len); // left part of given string
        right += left;
        return right; // right + left
    }
};
