//Question is something like that we have to string we can perform three type of operation insert remove replace  on first string inorder to make second string find out minimum number of operation we required in ordere to do so
//answer always possible by deleting  everything first string and insert second string character
//intution string matching 
//insert the same character
// delete the key and find something else
// replace and match
// This recursive solution its time complexity will be exponential that is 3^n
#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return f(i-1,j-1,s1,s2,dp);
    return dp[i][j]=1+min(f(i-1,j,s1,s2,dp),min(f(i,j-1,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
}
int mini_operation( string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
      f(n-1,m-1,str1,str2,dp);
      //Tabiulation
      //Since there is negative indexes involve in this recursion so we have to convert it into positive;
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      for(int i=0;i<=n;i++){
        dp[i][0]=i;
      }
      for(int j=0;j<=m;j++){
        dp[0][j]=j;
      }
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
      }
      return dp[n][m];
}
int main(){

}