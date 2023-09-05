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
            int tMin = minPalinPartition(s, i, k) + minPalinPartition(s, k + 1, j) + 1;
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