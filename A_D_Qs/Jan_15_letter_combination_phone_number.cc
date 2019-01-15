class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        string temp;
        vector<vector<char>> letters (2, vector<char>()); // make two empty vectors as index 0 and 1
        letters.push_back(vector<char>{'a', 'b', 'c'});
        letters.push_back(vector<char>{'d', 'e', 'f'});
        letters.push_back(vector<char>{'g', 'h', 'i'});
        letters.push_back(vector<char>{'j', 'k', 'l'});
        letters.push_back(vector<char>{'m', 'n', 'o'});
        letters.push_back(vector<char>{'p', 'q', 'r', 's'});
        letters.push_back(vector<char>{'t', 'u', 'v'});
        letters.push_back(vector<char>{'w', 'x', 'y', 'z'});
        dfs(letters, res, temp, 0, digits);
            
        return res;
    }
    void dfs (vector<vector<char>> &letters, vector<string>& res, string& temp, int index, const string& digits)
    {
        // each element in output should have the same length of input
        if (index == digits.length())
            res.push_back(temp);
        
        for (int i = 0; i < letters[digits[index]-'0'].size(); i++)
        {
            temp.push_back(letters[digits[index]-'0'][i]);
            // start with next index resulting in characters in each digit  
            dfs (letters, res, temp, index+1, digits);
            // backtracking part; need to clear the characters used previously
            temp.pop_back();
        }
    }
};
