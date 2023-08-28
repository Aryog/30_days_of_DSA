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
    // Using logic of Unbounded Knapsack Recursive Approach
    int subsetSumUnbounded(vector<int> &coins, int amount, int n)
    {
        if (n == 0 || amount <= 0)
        {
            return (amount == 0) ? 0 : INT_MAX - 1;
        }
        if (coins[n - 1] <= amount)
        {
            return min(1 + subsetSumUnbounded(coins, amount - coins[n - 1], n), subsetSumUnbounded(coins, amount, n - 1));
        }
        else
        {
            return subsetSumUnbounded(coins, amount, n - 1);
        }
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int res = subsetSumUnbounded(coins, amount, coins.size());
        return (res == INT_MAX - 1) ? -1 : res;
    }
};