class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            n = -n;
            x = 1.0/x;
        }
        return helper(x, n);
    }
    double helper (double x, int n)
    {
        if (n == 0)
            return 1.0;
        double half = helper(x, n / 2); // 
        if (n & 1) // number is odd or not 
            return half * half * x; // odd n = X^(n-1)  -> we need another x to find X^n
        else 
            return half * half;
    }
};
