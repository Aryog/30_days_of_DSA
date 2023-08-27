// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// DP method to solve this problem
// This problem is same as count number of subset of given difference
class Solution
{
public:
    // count the number of subsets with given sum
    int countOfSubset(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<int>> tb(n + 1, vector<int>(2 * sum + 1, 0));
        tb[0][sum] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < 2 * sum + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    tb[i][j] = tb[i - 1][j] + tb[i - 1][j - nums[i - 1]];
                }
                else
                {
                    tb[i][j] = tb[i - 1][j];
                }
            }
        }
        return tb[n][2 * sum];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int arraySum = 0;
        for (int i = 0; i < nums.size(); i++)
            arraySum += nums[i];
        // Check if it's possible to achieve the target sum
        if (target > arraySum || (target + arraySum) % 2 != 0)
        {
            return 0; // It's not possible, so return 0
        }
        int sum = (target + arraySum) / 2;
        return countOfSubset(nums, sum);
    }
};