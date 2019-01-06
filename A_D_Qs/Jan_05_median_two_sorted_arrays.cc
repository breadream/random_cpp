class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty())
        {
           vector<int> half = nums1.empty() ? nums2 : nums1; 
           return half.size() % 2 == 0 ? (half[half.size()/2-1] + half[half.size()/2]) / 2.0 : half[half.size()/2];
        }
        else 
        {
            vector<int> merged;
            vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
            while (it1 != nums1.end() && it2 != nums2.end())  
            {
                if(*it1 < *it2)
                {
                    merged.push_back(*it1);
                    ++it1;
                    if (it1 == nums1.end())
                        while (it2 != nums2.end())
                        {
                            merged.push_back(*it2);
                            ++it2;
                        }
                }
                else 
                {
                    merged.push_back(*it2); 
                    ++it2;
                    if (it2 == nums2.end())
                        while (it1 != nums1.end())
                        {
                            merged.push_back(*it1);
                            ++it1;
                        }
                }
            }
            return merged.size() % 2 != 0 ? merged[merged.size()/2] : (merged[merged.size()/2-1] + merged[merged.size()/2]) / 2.0;
        }
    }
};
