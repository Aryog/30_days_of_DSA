// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation:
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.

class Solution
{
public:
    // print the shortest common supersequence
    string shortestCommonSupersequence(string str1, string str2)
    {
        string str = "";
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < n + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // above we got the LCS
        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                str.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    str.push_back(str2[j - 1]);
                    j--;
                }
                else
                {
                    str.push_back(str1[i - 1]);
                    i--;
                }
            }
        }
        // Remaining ith and jth term
        while (i > 0)
        {
            str.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            str.push_back(str2[j - 1]);
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};