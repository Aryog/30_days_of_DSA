// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.

class Solution
{
public:
    int LCS(string X, string Y, int m, int n)
    {
        // Writing the DP solution

        vector<vector<int>> tb(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m + 1; i++)
            tb[i][0] = 0;
        for (int j = 0; j < n + 1; j++)
            tb[0][j] = 0;
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (X[i - 1] == Y[j - 1])
                {
                    tb[i][j] = 1 + tb[i - 1][j - 1];
                }
                else
                {
                    tb[i][j] = max(tb[i - 1][j], tb[i][j - 1]);
                }
            }
        }
        return tb[m][n];

        // Using the recursive approach

        // if(m==0 || n==0){
        //     return 0;
        // }
        // if(X[m-1] == Y[n-1]){
        //     return 1 + LCS(X,Y,m-1,n-1);
        // } else {
        //     return max(LCS(X,Y,m-1,n),LCS(X,Y,m,n-1));
        // }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return LCS(text1, text2, text1.length(), text2.length());
    }
};