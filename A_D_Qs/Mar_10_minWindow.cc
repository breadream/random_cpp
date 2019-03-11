class Solution {
public:
    string minWindow(string s, string t) {      
        if (s.length() * t.length() == 0)
            return "";
        
        vector<int> map (128, 0);
        int left = 0;
        int right = 0;
        int count = 0;
        
        int minLen = INT_MAX;
        string minWin = "";
        
        for (char c : t)
            map[c]++;
        
        while (right < s.size())
        {
            if (map[s[right++]]-- > 0) // char in t 
                count++;
            while (count == t.size())
            {
                int currLen = right - left; // should not +1 to right because 1 is already added in map[s[right"++"]]--
                if (minLen > currLen)
                {
                    minLen = currLen;
                    minWin = s.substr(left, minLen);
                }
                if (++map[s[left++]] > 0)
                    count--;
            }
        }
           
        return minWin;
    }
};
