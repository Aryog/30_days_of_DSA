// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

// NOTE*: A subarray is a contiguous part of any given array.

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        // code here
        int i = 0;
        int j = 0;
        long sum = 0;
        long mx = INT_MIN;
        while (j < N)
        {
            sum = sum + Arr[j];
            if (j - i + 1 < K)
            {
                j++;
            }
            else if (j - i + 1 == K)
            {
                mx = max(mx, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};