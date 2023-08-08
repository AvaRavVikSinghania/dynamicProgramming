#include<bits/stdc++.h>
using namespace std;
string common_string( string s,string t){
    int n=s.size();
    int m=t.size();
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
    int common_length=n+m-dp[n][m];
    string common="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            common+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            common+=s[i-1];
            i--;
        }
        else {
             common+=t[j-1];
             j--;
        }
    }
    while(i>0){
        common+=s[i-1];
        i--;
    }
    while(j>0){
        common+=t[j-1];
        j--;
    }
    reverse(common.begin(),common.end());
    return common;
}
int main(){

}