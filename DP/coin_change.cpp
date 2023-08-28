// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

class Solution
{
public:
    // Using logic of Unbounded Knapsack DP like Rod Cutting
    int subsetSumUnbounded(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> tb(n + 1, vector<int>(amount + 1));
        for (int i = 0; i < amount + 1; i++)
            tb[0][i] = INT_MAX - 1;
        for (int j = 0; j < n + 1; j++)
            tb[j][0] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    tb[i][j] = min(tb[i - 1][j], 1 + tb[i][j - coins[i - 1]]);
                }
                else
                {
                    tb[i][j] = tb[i - 1][j];
                }
            }
        }
        return tb[n][amount] == INT_MAX - 1 ? -1 : tb[n][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int res = subsetSumUnbounded(coins, amount);
        return res;
    }
};