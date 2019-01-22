class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() < 3)
            return s.length();
        
        vector<int> char_freq (128, 0); // frequency of each character in s 
        int start = 0; // start index of the longest substring
        int maxLen = 2; // default for length of 2 substring 
        int count = 0; // counter for distinct characters 
        for (int end = 0; end <= s.length(); end++)
        {
            if (++char_freq[s[end]] == 1) // new character 
                count++;
            while (count > 2) // at most 2 distinct characters
            {
                if (--char_freq[s[end]] == 0)
                    count--;
                start++; // increment the start pointer 
            }
            maxLen = max(maxLen, end+1 -start);
        }
        return maxLen;
    }
};
