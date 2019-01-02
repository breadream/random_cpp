// naive approach
int targetSum (const vector<int>& nums, int target)
{
	return targetSum(nums, target, 0, 0); 
}
int targetSum (vector<int>& nums, int target, int i, int sum)
{
	// When every item is passed, check if we've reached our target sum
	if (i == nums.size())
		return sum == target ? 1 : 0;

	// Combine possibilities by adding and subtracting the current value
	return targetSum (nums, target, i+1, sum + nums[i]) +
		   targetSum (nums, target, i+1, sum - nums[i]);
}
