class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0 ? true : false;
        if (neg)
            x *= -1; 
        
        long int ans = 0; // long int -> 32 bit integer
        while (x > 0)
        {
            ans = 10 * ans + x % 10; 
            x /= 10;
        }
        if (ans < INT_MIN || ans > INT_MAX)
            return 0;
        return neg ? -ans : ans;
    }
};
