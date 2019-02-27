class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map (256, -1); // the total number of Characuters in ASCII table is 256
        int ans = 0, j = -1; // j keeps track of the index where the repetition has happened
        for (int i = 0; i < s.length(); i++)
        {
            if (map[s[i]] > j) // if the current character is in the map
                j = map[s[i]]; // update the index of repetition point
            map[s[i]] = i; // set the index as current character's index
            ans = max(ans, i - j);
        }
        return ans;
    }
};
