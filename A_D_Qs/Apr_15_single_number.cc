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

int singleNumber(vector<int>& nums) {
	// if we take XOR of zero and some bit, it will return that bit
	// a ^ 0 = a
	// if we take XOR of two same bits, it will return 0;
	// a ^ a = 0

	int num = 0;
	for (const int i : nums)
		num ^= i;
	return num;
}
