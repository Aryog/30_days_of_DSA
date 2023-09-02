// Given string str, find the length of the longest repeating subsequence
// such that it can be found twice in the given string.
// Input:
// str = "AABEBCDD"
// Output: 3
// Explanation: The given string has longest subsequence as "ABD" which is repeating

class Solution
{
public:
    int LCS_non_repeating(string str1, string str2)
    {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1] && i != j)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        // I need to find the LCS between 2 same strings but not directly below but other than i!=j
        return LCS_non_repeating(str, str);
    }
};