class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int i)
    {
        // ans.push_back(ds);
        if (i == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(nums, ans, ds, i + 1);
        ds.pop_back();
        solve(nums, ans, ds, i + 1);
        return;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, ans, ds, 0);
        return ans;
    }
};