class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        
        int sum = 0;
        int sign = 1; // represent + (1)
        int num = 0;
        stack<char> stack; // container for sign
        stack.push(sign); // default sign = '+'
        
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else if (s[i] == '+' || s[i] == '-')
            {
                sum += sign * num;
                sign = stack.top() * (s[i] == '+' ? 1 : -1);
                num = 0;
                cout << sum << endl;
                
            }
            else if (s[i] == '(')
                stack.push(sign);
            else if (s[i] == ')')
                stack.pop();
        }
        
        sum += sign * num;
        return sum;
    }
};
