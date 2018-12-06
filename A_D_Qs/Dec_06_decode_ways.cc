class Solution {
public:
    int numDecodings(string s) 
    {
		vector <int> (s.length()+1, 0); // for memoization; default value = 0
		return heleper(s, s.length(), memo); 
    }
private:
    int helper(string s, int k, vector<int>& memo) // going from left to right 
    {
		int start = s.length() - k; // starting from left 
		int ans;
		if (start == 0) // end of recursion 
			return 1;

		if (s[start] == '0') // invalid / also check the number is greater than equal to 10
			return 0;		 

		if (memo[k] != 0) // memoization table check
			return memo[k]; // return the intermediate value instead of calculating redundantly 

		ans = helper(s, k-1, memo); // go to next index 

		if (k >= 2 && atoi(s.substr(start, 2).c_str()) <= 26) // 10 <= substr -> already checked previously 
			ans += helper(s, k-2, memo);

		memo[k] = ans; // memoization for current result

		return ans;
    }
// version 2 // only DP
 class Solution {
public:
    int numDecodings(string s)
    {
        if (s.length() == 0)
            return 0;
        int n = s.length();
        vector<int> memo (n+1, 0); // memo [n]; total number of ways to make n
        memo[0] = 1; // empty string
        memo[1] = (s[0] != '0') ? 1 : 0; // string of size 1
        for (int i = 2; i <= n; i++)
        {
            int first  = stoi(s.substr(i-1,1).c_str());
            int second = stoi(s.substr(i-2,2).c_str());
            memo[i] += (first >= 1 && first <= 9)? memo[i-1] : 0;
            memo[i] += (second >= 10 && second <= 26)? memo[i-2] : 0;
        }
        return memo[n];
    }
};
};
