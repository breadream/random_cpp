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
};
