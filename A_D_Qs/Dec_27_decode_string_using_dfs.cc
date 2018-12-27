class Solution {
public:
    string decodeString(string s) 
    {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(string& s, int& i)
    {
        string res = "";
        int count = 0;
        for (; i < s.length() && s[i] != ']'; i++) // loop stops when it encounters ']' 
        {
            if (isdigit(s[i]))
                count = count * 10 + s[i] - '0';
            else if (isalpha(s[i]))
                res.push_back(s[i]);
            else if (s[i] == '[')
            {
                string nested = decodeString(s, ++i); // to skip '[' 
                for (; count != 0; count--)
                    res += nested;
            }
        }
        return res;
    }
};
