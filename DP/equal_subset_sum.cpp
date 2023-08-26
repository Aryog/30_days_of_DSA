// It's related to the knapsack solution
class Solution
{
public:
    bool subsetsum(vector<int> &arr, int sum, int n)
    {
        vector<vector<bool>> tb(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    tb[i][j] = false;
                }
                if (j == 0)
                {
                    tb[i][j] = true;
                }
            }
        }
        tb[0][0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (j >= arr[i - 1])
                {
                    tb[i][j] = tb[i - 1][j] || tb[i - 1][j - arr[i - 1]];
                }
                else
                {
                    tb[i][j] = tb[i - 1][j];
                }
            }
        }
        return tb[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        else
        {
            return subsetsum(nums, sum / 2, nums.size());
        }
    }
};