#include<bits/stdc++.h>
using namespace  std;
// given two string return maximum substring 
int f(int i,string s,int  j,string t, vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]= 1+f(i-1,s,j-1,t,dp);
    //int equal=1+f(i-1,s,j-1,t);
    //int not_equal=max(f(i-1,s,j,t),f(i,s,j-1,t));
    return dp[i][j]= max(f(i-1,s,j,t,dp),f(i,s,j-1,t,dp));
    //return max(equal,not_equal);
}
// sifting of index
int ff(int i,string s,int j,string t,vector<vector<int>>&dp){
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) dp[i][j];
    if(s[i-1]==t[j-1]) return dp[i][j]=1+f(i-1,s,j-1,t,dp);
     return dp[i][j]=max(f(i-1,s,j,t,dp),f(i,s,j-1,t,dp));
}
int lcs(string s,string t){
    int n=s.size();
    int m=t.size();
    //vector<vector<int>>dp(n,vector<int>(m,-1));
   //Tabulation
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i=0;i<=m;i++){
    dp[0][i]=1;
   }
   for(int i=0;i<=n;i++){
    dp[i][0]=0;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        // copy the recurrence
        if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
   }
   return dp[n][m];
    //return f(n-1,s,m-1,t,dp);

}
// space optimisation
int lcs2(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++) prev[j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(prev[j],curr[j-1]);
        }
        prev=curr;
    }
    return prev[m];
}
int main(){
      string a="abcd";
      string b="bd";
      cout<<lcs(a,b);
      cout<<lcs2(a,b);
      return 0;
}