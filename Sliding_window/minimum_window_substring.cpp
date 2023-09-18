// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ans = "";
        int i = 0;
        int j = 0;
        map<char, int> mpp;
        for (auto &x : t)
            mpp[x]++;
        int count = mpp.size();
        int win_length = s.length() + 1;
        int start_ind = 0;
        while (j < s.length())
        {
            if (mpp.find(s[j]) != mpp.end())
            {
                mpp[s[j]]--;
                if (mpp[s[j]] == 0)
                    count--;
            }
            while (count == 0)
            {
                // window hit
                if (j - i + 1 < win_length)
                {
                    win_length = j - i + 1;
                    start_ind = i;
                }
                if (mpp.find(s[i]) != mpp.end())
                {
                    // if present
                    mpp[s[i]]++;
                    if (mpp[s[i]] == 1)
                        count++;
                }
                i++;
            }
            j++;
        }
        return (win_length == s.length() + 1) ? "" : s.substr(start_ind, win_length);
    }
};