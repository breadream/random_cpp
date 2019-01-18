class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack (vector<string>& res, string temp, int open, int end, int max) 
    {
        if (temp.length() == max*2)
        {
            res.push_back(temp);
            return;
        }
        // once we add '(' then try add ')' which can only close valid '('
        if (open < max)
            backtrack(res, temp+'(', open+1, end, max);
        // try to close the open bracket (open bracket is already present) 
        if (end < open)
            backtrack(res, temp+')', open, end+1, max);
    }
};
