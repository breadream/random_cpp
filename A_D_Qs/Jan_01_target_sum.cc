// naive approach
int targetSum (const vector<int>& nums, int target)
{
	return targetSum(nums, target, 0, 0); 
}
int targetSum (const vector<int>& nums, int target, int i, int sum)
{
	// When every item is passed, check if we've reached our target sum
	if (i == nums.size())
		return sum == target ? 1 : 0;

	// Combine possibilities by adding and subtracting the current value
	return targetSum (nums, target, i+1, sum + nums[i]) +
		   targetSum (nums, target, i+1, sum - nums[i]);
}

// Top down DP approach
int targetSum(const vector<int>& nums, int target)
{
	// i -> sum -> val
	unordered_map<int, unordered_map<int, int>> cache;
	return targetSum(nums, target, 0, 0, cache);
}

int targetSum(const vector<int>& nums, int target, int i, int sum, unordered_map<int, unordered_map<int, int>& cache) 
{
	if (i == nums.size())
		return sum == target ? 1 : 0;

	// Check the cache and return if we get a hit
	if (cache.count(i))
		int cached = (cache.find(i)->second)->second;
		if (!cached)
			return cached;
	
	// if we didn't hit in the cache, compute the value and store to cache
	int returnValue = targetSum(nums, target, i+1, sum-nums[i], cache) + 
				  targetSum(nums, target, i+1, sum+nums[i], cache);
	cache[i].insert({sum, returnValue});
	return returnValue;
}

// Bottom up approach
int targetSum (const vector<int>& nums, int target)
{
	// Cache has to ragne from -sum(nums) to +sum(nums)
	// so we need to offset everything by sum
	int sum = 0;
	for (int num : nums)
		sum += num;
	// combination of adding and subtracting the first i numbers
	vector<vector<int>> cache (nums.size()+1, vector<int>(2*num+1, 0));
	if (sum == 0)
		return 0;
	// baseline; i = 0, target = 0;; there's one way to have sum = 0 (there's no element) 
	cache[0][sum] = 1;

	// Start from deciding to add the first element as positive or negative
	for (int i = 1; i <= nums.size(); i++)
		for (int j = 0; j < 2*sum+1; j++)
		{
			int prev = cache[i-1][j]; 
			// if current sum (j - sum) is already reached by the previous searched numbers
			if (prev != 0)
			{
				cache[i][j - nums[i-1]] += prev;
				cache[i][j + nums[i-1]] += prev;
			}
		}
	return cache[nums.size()][sum + target];

}



