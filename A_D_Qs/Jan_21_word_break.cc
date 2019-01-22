class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> wordSet; 
        for (auto const& word : wordDict)
            wordSet.insert(word);
        
        vector<bool> dp (s.length()+1, false);
        dp[0] = true; // empty string is always satisfied  
        
        // 0 . . . . i . . . . j . . . s.length() 
        for (int j = 1; j <= s.length(); j++) // j = end index of the second string 
        {
            for (int i = 0; i < j; i++) // i = partitioning index that separates first and second strings 
            {
                // dp[i] = first part of string is composed of the words in dictionary? 
                // s.substr(i, j-i) -> the second string is in word dictionary
                if (dp[i] && wordSet.count(s.substr(i, j-i))) 
                {
                    dp[j] = true; // strings upto j consist of the words in dicionary
                    break;
                }
            }
        }
        // check the whole string is composed of the words in dicionary
        return dp[s.length()];
    }
};
