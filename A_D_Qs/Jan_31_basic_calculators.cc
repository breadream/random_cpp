class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        int sum = 0;
        int tempNum = 0;
        int sign = 1; // 1 => +, -1 => -
        stack <int> signs; // keep track of signs in front of opening curly bracket
        signs.push(sign); // push the default sign 
        
        for (const char & c : s)
            if (isdigit(c))
                tempNum = 10 * tempNum + (c - '0'); // deal with numbers with more than one digit
            else if (c == '+' || c == '-') // operator is in between operands
            {
                sum += sign * tempNum; // calculate the sum with pre-existing number 
                tempNum = 0; // reset temp num since it's already used
                sign = signs.top() * (c == '+' ? 1 : -1); // get the outer operator  
            }
            else if (c == '(') // opening curly bracket => need to store the outer operator 
                signs.push(sign);
            else if (c == ')') // remove operator in front of opening curly braket
                signs.pop();
            
        sum += sign * tempNum; // add the last number with its operator
        return sum;
    }
};
