// Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

// Note :-  l and r denotes the starting and ending index of the array.

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // To solve in better than nlogk I can use the quick select algorithm to remove TLE.
        priority_queue<int> maxh;
        for (int i = l; i <= r; i++)
        {
            maxh.push(arr[i]);
            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }
        return maxh.top();
    }
};