class Solution {
public:
    string decodeString(string s) {
        stack <int> countStack;
        stack <string> strStack;
        string res = "";
        int index = 0;
        while (index < s.length())
        {
            if (isdigit(s[index]))
            {
                int count = 0;
                while (isdigit(s[index]))
                {
                    count = count * 10 + s[index] - '0'; // consider more than two digits
                    index++; 
                }
                countStack.push(count);
            }
            else if (s[index] == '[') 
            {
                strStack.push(res); // on the first [, empty string is added -> "" + res .... 
                res = "";
                index++;
            }
            else if (s[index] == ']')
            {
                string temp = strStack.top();
                strStack.pop();
                int repeatCount = countStack.top();
                countStack.pop();
                for (int i = 0; i < repeatCount; i++) // add current strs to temp
                    temp += res;
                res = temp;
                index++;
            }
            else // if it is a character 
            {
                res += s[index];
                index++;
            }
        }
        return res;
    }
};
