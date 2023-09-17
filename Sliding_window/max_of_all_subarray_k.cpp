// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output:
// 3 3 4 5 5 5 6
// Explanation:
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int i = 0;
        int j = 0;
        int tempans = 0;
        vector<int> ans;
        deque<int> dq;
        while (j < n)
        {
            // tempans = max(tempans,arr[j]);
            while (!dq.empty() && dq.back() < arr[j])
                dq.pop_back();
            dq.push_back(arr[j]);

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                ans.push_back(dq.front());
                if (dq.front() == arr[i])
                    dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};