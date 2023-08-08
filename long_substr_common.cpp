#include<bits/stdc++.h>
using namespace std;
int lcs(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
             ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
    // Space optimisation
    int ans2=0;
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                curr[j]=1+prev[j-1];
                ans2=max(ans2,curr[j]);
            }
            else curr[j]=0;
        }
        prev=curr;
    }
    return ans2;

}
int main(){
    
}