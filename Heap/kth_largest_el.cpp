// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // using the min heap so that the top has smallest element
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int i = 0; i < nums.size(); i++)
        {
            minh.push(nums[i]);
            if (minh.size() > k)
            {
                minh.pop();
            }
        }
        return minh.top();
    }
};