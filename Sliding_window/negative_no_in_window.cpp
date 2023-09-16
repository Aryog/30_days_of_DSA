// Given an array A[] of size N and a positive integer K,
// find the first negative integer for each and every window(contiguous subarray) of size K.
// Input :
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output :
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    int i = 0;
    int j = 0;
    vector<int> list;
    vector<long long> ans;
    while (j < N)
    {
        if (A[j] < 0)
        {
            list.push_back(A[j]);
        }
        if (j - i + 1 < K)
            j++;
        else if (j - i + 1 == K)
        {
            // calculate the ans
            if (list.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(list.front());
                // if leaving the window of negative number
                if (list.front() == A[i])
                    list.erase(list.begin());
            }
            j++;
            i++;
        }
    }
    return ans;
}