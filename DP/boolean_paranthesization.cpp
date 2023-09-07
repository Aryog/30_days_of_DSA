// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates
// to true in 4 ways ((T|T)&(F^T)),
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function countWays()
// which takes N and S as input parameters and returns number of possible ways modulo 1003.

class Solution
{
public:
    unordered_map<string, int> mpp;
    int solve(string s, int i, int j, bool isTrue)
    {
        if (i > j)
            return false;
        if (i == j)
        {
            if (isTrue == true)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (mpp.find(temp) != mpp.end())
            return mpp[temp];
        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lT = solve(s, i, k - 1, true);
            int lF = solve(s, i, k - 1, false);
            int rT = solve(s, k + 1, j, true);
            int rF = solve(s, k + 1, j, false);

            if (s[k] == '&')
            {
                if (isTrue)
                {
                    ans = (ans + (lT * rT) % 1003) % 1003;
                }
                else
                {
                    ans = (ans + (lT * rF) % 1003 + (lF * rT) % 1003 + (lF * rF) % 1003) % 1003;
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue)
                {
                    ans = (ans + (lT * rF) % 1003 + (lF * rT) % 1003 + (lT * rT) % 1003) % 1003;
                }
                else
                {
                    ans = (ans + (lF * rF) % 1003) % 1003;
                }
            }
            else
            {
                if (isTrue)
                {
                    ans = (ans + (lT * rF) % 1003 + (lF * rT) % 1003) % 1003;
                }
                else
                {
                    ans = (ans + (lF * rF) % 1003 + (lT * rT) % 1003) % 1003;
                }
            }
        }
        return mpp[temp] = ans;
    }

    int countWays(int N, string S)
    {
        // Code here
        // Here I am using the recursive approach at first
        // Question is asking to find min ways that make the expression True hence passing true
        mpp.clear();
        return solve(S, 0, N - 1, true);
    }
};