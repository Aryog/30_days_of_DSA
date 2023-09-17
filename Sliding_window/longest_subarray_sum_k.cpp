// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution
{
public:
    // Works for the positive numbers in the array
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int i = 0;
        int j = 0;
        int max_el = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            if (sum < k)
                j++;
            else if (sum == k)
            {
                max_el = max(max_el, j - i + 1);
                j++;
            }
            else if (sum > k)
            {
                while (sum >= k)
                {
                    sum -= nums[i];
                    i++;
                }
            }
        }
        return max_el;
    }
};