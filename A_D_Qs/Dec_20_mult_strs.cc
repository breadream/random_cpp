class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length(), m = num2.length();
        if ((n == 1 && num1[0] == '0') || (m == 1 && num2[0] == '0'))
            return "0";
            
        string res (n + m, '0'); // fill constructor, maximum length is num1.length + num2.length
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = m-1; j >= 0; j--)
            {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i+j+1] - '0');
                res[i+j+1] = sum % 10 + '0';
                res[i+j] += sum / 10; // res[i+j] is already res[i+j] = '0'
            }
        }
        // remove leading zeros
        for (int i = 0; i < n + m; i++)
            if (res[i] != '0')
                return res.substr(i);
        
        return res;
    }
};
