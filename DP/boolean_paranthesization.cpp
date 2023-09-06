// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates
// to true in 4 ways ((T|T)&(F^T)),
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

class Solution
{
public:
    int SolveRecurr(string s, int i, int j, bool isTrue)
    {
        // base condition
        if (i > j)
        {
            return false;
        }
        if (i == j)
        {
            if (isTrue == true)
            {
                return s[i] == 'T';
            }
            else
            {
                return s[i] == 'F';
            }
        }

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lT = SolveRecurr(s, i, k - 1, true);
            int lF = SolveRecurr(s, i, k - 1, false);
            int rT = SolveRecurr(s, k + 1, j, true);
            int rF = SolveRecurr(s, k + 1, j, false);

            // now we will check for each operator (&, |, ^)
            if (s[k] == '&')
            {
                if (isTrue == true)
                {
                    ans += (lT * rT); // both should be true
                }
                else
                {
                    ans += (lF * rT) + (lT * rF) + (lF * rF); // any one / both should be false
                }
            }
            else if (s[k] == '|')
            {
                if (isTrue == true)
                {
                    ans += (lT * rT) + (lT * rF) + (lF * rT); // any one should be true
                }
                else
                {
                    ans += (lF * rF); // both should be false
                }
            }
            else if (s[k] == '^')
            {
                if (isTrue == true)
                {
                    ans += (lT * rF) + (lF * rT); // xor condition
                }
                else
                {
                    ans += (lT * rT) + (lF * rF);
                }
            }
        }
        return ans;
    }
    int countWays(int N, string S)
    {
        // code here
        // Here I am using the recursive approach at first
        // Question is asking to find min ways that makes the expression True hence passing true
        return SolveRecurr(S, 0, N - 1, true);
    }
};