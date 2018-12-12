class Solution {
public:
    void reverseWords(string &s) {
        reverse(s, 0, s.length()-1);
        int i = 0, j = 0;
        while (i < s.length())
        {
             while (i < j) i++;
             while (i < s.length() && s[i] == ' ') i++; // skip spaces
             while (j < i) j++;
             while (j < s.length() && s[j] != ' ') j++; // skip non spaces
             reverse(s, i, j - 1);                      // reverse the word
        }
        clean_spaces(s);
    }
    
    void clean_spaces(string &s)
    {
        int i = 0, j = 0;
        while (j < s.length())
        {
            while (j < s.length() && s[j] == ' ') j++; // j might be ahead of i, so balance it 
            while (j < s.length() && s[j] != ' ') s[i++] = s[j++]; // keep non spaces 
            while (j < s.length() && s[j] == ' ') j++; // i might be ahead of j, so balance it 
            if (j < s.length()) s[i++] = ' '; // keep only one space 
        }
        s = s.substr(0, i);
    }
    void reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            char c = s[i];
            s[i++] = s[j];
            s[j--] = c;
        }
    }
};
