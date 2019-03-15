class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())
            return res;
        unordered_map <string, vector<string>> map;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            if (map.count(copy))
                map[copy].push_back(strs[i]);
            else
                map[copy].push_back({strs[i]});
        }
        
        for (auto it = map.begin(); it != map.end(); it++)
        {
            res.push_back(it->second);
        }
        
        return res;
    }
};
