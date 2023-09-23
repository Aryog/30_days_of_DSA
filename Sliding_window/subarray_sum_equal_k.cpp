// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // Using hash map more like a dp solution since {0,1} in map initialize
        int count = 0, sum = 0;
        unordered_map<int, int> mpp;
        mpp[0]++; // {sum , count} by the way sum is sum - k
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (mpp.find(sum - k) != mpp.end())
            {
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};