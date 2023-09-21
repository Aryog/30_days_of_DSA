// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        // made the map
        // now building heap using map

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            // most frequent k
            minh.push({i->second, i->first});
            if (minh.size() > k)
                minh.pop();
        }
        vector<int> ans;
        while (minh.size() > 0)
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};