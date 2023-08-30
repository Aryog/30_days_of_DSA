// Input Format:
// The custom test case should contain only 3 lines. First line should contain the length of the strings n and m. The second line should contain the string S1. The third line should contain the string S2.
// Example:

// 6 6
// ABCDGH
// ACDGHR
// Expected Output: 4 (CDGH)

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // Here I use the DP solution to solve this problem
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int maxLen = 0;
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < m + 1; j++)
            dp[0][j] = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLen = max(maxLen, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}