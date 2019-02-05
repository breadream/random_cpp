class Solution {
public:
    // basic idea; while iterating through each digit in num, if we find the smaller digit than previous digit 
    // than pop the previous one (bigger one), and decrement k
    // key; we just need to keep the small numbers 
    string removeKdigits(string num, int k) {
        // base case 
        if (num.length() == k)
             return "0";
        
        stack <int> smallNums;
        int count = k;
        for (int i = 0; i < num.length(); i++)
        {
            // remove all digits from stack that are bigger than current digit
            // "greedy method"
            while (count > 0 && !smallNums.empty() && (num[i]-'0') < smallNums.top())
            {
                smallNums.pop(); // we don't need the bigger nums 
                count--;
            }
            smallNums.push(num[i]-'0'); // keep pushing each digit in num
        }
        // result string
        string res (smallNums.size(), '0');
        for (int i = smallNums.size()-1; i >= 0; i--)
        {
            res[i] = smallNums.top()+'0';
            smallNums.pop();
        }
        
        cout << res << endl;
        int begin = 0, limit = num.length()-k;
        while (begin < limit && res[begin] == '0')
            begin++;
            
        return begin == limit ? "0" : res.substr(begin, limit-begin);
    }
};
