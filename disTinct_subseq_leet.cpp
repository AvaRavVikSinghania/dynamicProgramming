#include <bits/stdc++.h>
using namespace std;
int f(int i, string s, int j, string t, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
    {
        return dp[i][j] = f(i - 1, s, j - 1, t, dp) + f(i - 1, s, j, t, dp);
    }
    return dp[i][j] = f(i - 1, s, j, t, dp);
}
int distinct_subseq(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n - 1, s, m - 1, t, dp);
    // tabulation
    //  converting 1 base indexing
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
int main()
{
}