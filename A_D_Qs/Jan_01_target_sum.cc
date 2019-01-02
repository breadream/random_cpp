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
