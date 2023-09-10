// You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

// You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

// Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

class Solution
{
    // Binary Search solution used with DP
public:
    static int dp[101][10001];
    int solve(int k, int n)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (dp[k][n] != -1)
            return dp[k][n];
        int mn = INT_MAX, l = 1, h = n, temp = 0;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            int left = solve(k - 1, mid - 1); // egg broken check for down floors
            int right = solve(k, n - mid);    // not broken check for up floors
            temp = 1 + max(left, right);
            if (left < right)
            {
                l = mid + 1; // l = mid + 1 to gain more temp for worst case
            }
            else
            {
                h = mid - 1;
            }
            mn = min(mn, temp);
        }
        return dp[k][n] = mn;
    }
    int superEggDrop(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};
int Solution::dp[101][10001];