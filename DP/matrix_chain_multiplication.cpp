// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension
// 40x20, 20x30, 30x10, 10x30. Say the matrices are
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D.
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int static tb[1001][1001];
    Solution()
    {
        memset(tb, -1, sizeof(tb));
    }
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        if (tb[i][j] != -1)
        {
            return tb[i][j];
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempar = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
            mn = min(mn, tempar);
            tb[i][j] = mn;
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // Using the recursion with memoization
        // memset(t,-1,sizeof(t));
        return solve(arr, 1, N - 1);
    }
};
int Solution::tb[1001][1001];

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}