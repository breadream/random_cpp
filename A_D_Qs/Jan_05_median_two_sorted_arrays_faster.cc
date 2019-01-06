class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // nums1 size should be less than num2's 
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size();
        int y = nums2.size();
        // first array is the base line 
        int low = 0;
        int high = x;
        
		// ''''''''''partX'''''''''''
		// '''''''''''''''''''partY'''''''''''''''''''''''
		/* basically a binary serach based on X */
        while (low <= high)
        {
            // partX + partY = x + y + 1 // to make the lengths of merged partitioned arrays same 
            int partX = (low + high) / 2;
            int partY = (x + y + 1) / 2 - partX; // to make it easy for even number 
            
            // partX = 0 ? -> nothing is there on left side. Set it as INT_MIN
            // partaX = x ? -> nothng is there on right side. Set it as INT_MAX
            int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX-1];
            int minRightX = (partX == x) ? INT_MAX : nums1[partX];
            
            int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY-1];
            int minRightY = (partY == y) ? INT_MAX : nums2[partY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) // all left sides of both X and Y are less than right sides
            {
                if ((x + y) % 2 == 0) // both even number size?
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                else 
                    return max(maxLeftX, maxLeftY);
            }
            else if (maxLeftX > minRightY) // too far on right side for partX. Go on left side
                high = partX - 1;
            else // too far on left side for partX. Go on right side
                low = partX + 1;
        }
    }
};
