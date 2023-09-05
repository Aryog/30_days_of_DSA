// Given a string s, partition s such that every
// substring
//  of the partition is a
// palindrome
// .

// Return the minimum cuts needed for a palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minPalinPartition(string &s, int i, int j, vector<int> &dp)
    {
        if (i >= j || isPalindrome(s, i, j))
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            if (isPalindrome(s, i, k))
            {
                int temp = minPalinPartition(s, k + 1, j, dp) + 1;
                mn = min(mn, temp);
                dp[i] = mn;
            }
        }
        return mn;
    }
    int minCut(string s)
    {
        // Using the DP as MCM problem to solve
        int len = s.length();
        /* Only i is changing so 1D DP used*/
        vector<int> dp(len + 1, -1);
        return minPalinPartition(s, 0, len - 1, dp);
    }
};