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
    int static t[2001][2001];
    Solution()
    {
        memset(t, -1, sizeof(t));
    }
    bool isPalindrome(string s, int i, int j)
    {
        if (i >= j)
        {
            return true;
        }
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minPalinPartition(string s, int i, int j)
    {
        if (i >= j || isPalindrome(s, i, j))
        {
            return 0;
        }
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int left;
            int right;
            if (t[i][k] != -1)
                left = t[i][k];
            else
            {
                left = minPalinPartition(s, i, k);
                t[i][k] = left;
            }

            if (t[k + 1][j] != -1)
                right = t[k + 1][j];
            else
            {
                right = minPalinPartition(s, k + 1, j);
                t[k + 1][j] = right;
            }
            int tMin = left + right + 1;
            mn = min(mn, tMin);
            t[i][j] = mn;
        }
        return mn;
    }
    int minCut(string s)
    {
        // Using the DP as MCM problem to solve
        int len = s.length();
        return minPalinPartition(s, 0, len - 1);
    }
};
int Solution::t[2001][2001];