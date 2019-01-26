class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map <string, vector<string>> map; // <sorted, originals>
        for (string str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            map[temp].push_back(str);
        }
        for (auto originals : map)
        {
            res.push_back(originals.second);
        }
        return res;
    }
};
