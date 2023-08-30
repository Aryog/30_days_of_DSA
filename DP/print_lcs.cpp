// You are given two strings s and t. Now your task is to print longest common sub-sequence

// Input: text1 = "abcde", text2 = "ace"
// Output: ace
// Explanation: The longest common subsequence is "ace" and its length is 3.

class Solution
{
public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<string> str;

        for (int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                str.push_back(string(1, s[i - 1]));
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};