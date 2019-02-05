class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack(num.length(), ' ');
        int top = 0; // top index for stack
        int count = k;
        for (const char & c : num)
        {
            while (count > 0 && top > 0 && stack[top-1] > c)
            {
                count--;
                top--;
            }
            stack[top++] = c;
        }
        int begin = 0, limit = num.length()-k; 
        while (begin < limit && stack[begin] == '0') // remove leading zeroes 
            begin++;
        
        string res = "";
        for (int i = begin; i < limit; i++)
            res += stack[i];
            
        return res == "" ? "0" : res;
    }
};
