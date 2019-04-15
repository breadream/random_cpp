  int singleNumber(vector<int>& nums) {
         unordered_map<int, int> map;
         int num;
         for (const int num : nums)
         {
             if (map.count(num))
                 map[num]++;
             else 
                 map[num] = 1;
         }
        
         for (auto & it : map)
             if (it.second == 1)
             {
                 num = it.first;
                 break;
             }
        return num;
    }
