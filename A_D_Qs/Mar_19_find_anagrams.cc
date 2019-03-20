 vector<int> findAnagrams(string s, string p) {
        // lowercase English letters only 
        vector<int> sMap (26, 0);
        vector<int> pMap (26, 0);
        vector<int> res;
        if (p.size() > s.size())
            return res;
        // get the frequency of characters in pattern 
        for (int i = 0; i < p.size(); i++)
        {
            ++pMap[p[i] - 'a'];
            ++sMap[s[i] - 'a'];
        }
        
        // if they have same combination, 0 is the starting index 
        if (sMap == pMap) 
            res.emplace_back(0);
        
        // iterating over each character in s
        for (int i = p.size(); i < s.size(); i++)
        {
            // one step to the right  
            ++sMap[s[i] - 'a'];
            
            // one step from left 
            --sMap[s[i - p.size()] - 'a'];
            
            if (sMap == pMap)
                res.emplace_back(i+1 - p.size());
        }
        return res;
    }
