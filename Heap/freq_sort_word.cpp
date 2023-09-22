// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.
// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        priority_queue<pair<int, char>> maxh;
        for (auto i = mpp.begin(); i != mpp.end(); i++)
        {
            maxh.push({i->second, i->first});
        }
        string ans = "";
        while (maxh.size() > 0)
        {
            int curr_freq = maxh.top().first;
            char curr_ch = maxh.top().second;
            while (curr_freq > 0)
            {
                ans += curr_ch;
                curr_freq--;
            }
            maxh.pop();
        }
        return ans;
    }
};