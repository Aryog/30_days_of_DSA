// We can scramble a string s to get a string t using the following algorithm:

// If the length of the string is 1, stop.
// If the length of the string is > 1, do the following:
// Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
// Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
// Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.compare(s2) == 0)
            return true;
        if (s1.length() <= 1)
            return false;
        int n = s1.length();
        bool flag = false;
        for (int i = 1; i <= n - 1; i++)
        {
            bool condition1 = isScramble(s1.substr(0, i), s2.substr(n - i, i)) == true && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)) == true;
            bool condition2 = isScramble(s1.substr(0, i), s2.substr(0, i)) == true && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)) == true;
            if (condition1 || condition2)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};