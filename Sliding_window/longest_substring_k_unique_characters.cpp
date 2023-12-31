// Given a string you need to print the size of the longest possible substring that has exactly K unique characters.
// If there is no possible substring then print -1.
// Input:
// S = "aabacbebebe", K = 3
// Output:
// 7
// Explanation:
// "cbebebe" is the longest substring with 3 distinct characters.

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        int ans = 0;
        int j = 0;
        int i = 0;
        map<char, int> mpp;
        while (j < s.length())
        {
            mpp[s[j]]++;
            if (mpp.size() < k)
                j++;
            else if (mpp.size() == k)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if (mpp.size() > k)
            {
                while (mpp.size() > k)
                {
                    mpp[s[i]]--;
                    if (mpp[s[i]] == 0)
                        mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};