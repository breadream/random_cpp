class Solution {
public:
    string minWindow(string s, string t) {      
        if (s.length() * t.length() == 0)
            return "";
           
        vector<int> map (128, 0); // the number of each character in s 
        
        for (auto c : t)
            map[c]--; // count down only the characters in t  
        
        int t_len = -t.length(); // zero means containing all the characters in t
        int min_begin = 0;
        int curr_start = 0;
        int min_length = INT_MAX;
        for (int end = 0; end < s.length(); end++)
        {
            char curr = s[end];
            if (map[curr] < 0) // if it is part of t
                t_len++;
            map[curr]++; // increment the current char's count 
            
            while (t_len == 0) // all chars in t are present
            {
                int curr_len = end+1 - curr_start;
                if (curr_len < min_length)
                {
                    min_length   = curr_len;
                    min_begin = curr_start;
                }
                // contract the window size by moving start index of the current window 
                char to_be_removed = s[curr_start];
                curr_start++;
                // if it belongs to t, decrement t_Len 
                if (map[to_be_removed] == 0) 
                    t_len--;
                map[to_be_removed]--;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_begin, min_length);
    }
};
