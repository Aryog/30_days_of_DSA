// Example 1
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int ptr_size = p.length();
        int str_size = s.length();
        map<char, int> mpp;
        for (auto &x : p)
            mpp[x]++;
        int count = mpp.size();
        while (j < str_size)
        {
            // window not hit till push in mapp
            if (mpp.find(s[j]) != mpp.end())
            {
                // found in map
                mpp[s[j]]--;
                if (mpp[s[j]] == 0)
                {
                    count--;
                }
            }
            // window size is ptr size
            if (j - i + 1 < ptr_size)
                j++;

            else if (j - i + 1 == ptr_size)
            {
                // window is hit check count if 0
                if (count == 0)
                {
                    ans.push_back(i);
                }
                if (mpp.find(s[i]) != mpp.end())
                {
                    mpp[s[i]]++;
                    if (mpp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};