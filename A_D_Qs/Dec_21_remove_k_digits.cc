class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s; // to keep smaller number 
        int count = k;
        for (const char c : num)
        {
            while (!s.empty() && s.top() > c && count > 0) // greedy method
            {
                s.pop(); // current < previous ? then remove previous, resulting in a smaller number
                count--;
            }
            s.push(c);
        }
        
        string ans (s.size(), '0');
        for (int i = s.size()-1; i >= 0; i--)
        {
            ans[i] = s.top();
            s.pop();
        }
        
        int begin = 0, limit = num.length()-k;
        while (begin < limit && ans[begin] == '0') // remove leading zeroes 
            begin++;
        
        return begin == limit ? "0" : ans.substr(begin, limit-begin);
    }
};
