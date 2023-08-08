// approach is reverese a string and select the common subsequence both of them
#include <bits/stdc++.h>
using namespace std;
int f(int i, string s, int j, string t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j - 1])
        return dp[i][j] = 1 + f(i - 1, s, j - 1, t, dp);
    return dp[i][j] = max(f(i, s, j - 1, t, dp), f(i - 1, s, j, t, dp));
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    reverse(t.begin(), t.end());
    return f(n - 1, s, m - 1, t, dp);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
int main()
{
}