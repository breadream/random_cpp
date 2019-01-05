class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map (256, -1); // the total number of Characuters in ASCII table is 256
        int ans = 0, j = -1; // j = the second pointer 
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s[i]] > j) // if it has been mentioned before? 
                j = map[s[i]]; // the index of already seen character
            map[s[i]] = i; // set the index of current character 
            
            ans = max(ans, i - j);
        }
        return ans;
    }
};
