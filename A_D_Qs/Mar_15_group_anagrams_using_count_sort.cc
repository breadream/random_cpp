class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string original = strs[i];
            string sorted = countSort(strs[i]);
            if (map.count(sorted))
                map[sorted].push_back(original);
            else
                map[sorted].push_back({original});
        }
        for (auto it = map.begin(); it != map.end(); it++)
            res.push_back(it->second);
        
        return res;
    }
    
    
    // since all characters are in lower case alphabets 
    string countSort (const string& s)
    {
        vector<int> table (26, 0);
        for (const char c : s)
            table[c - 'a']++;
        
        string res = "";
        for (int c = 0; c < 26; c++)
            res += string(table[c], c + 'a'); //  (number of each chars, char itself)
        
        return res;
    }
    
};

