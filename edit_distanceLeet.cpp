#include <bits/stdc++.h>
using namespace std;
int f(int i, string &s, int j, string &t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = f(i - 1, s, j - 1, t, dp);
    return dp[i][j] = min(f(i - 1, s, j, t, dp), min(f(i, s, j - 1, t, dp), f(i - 1, s, j - 1, t, dp)));
}
// Given two string we have to convert first string into second string by using three operation 1 remove ,delete and insert any character in string first//
int count(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // return f(n-1,s,m-1,t,dp);
    // Tabulation
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
int main()
{
}