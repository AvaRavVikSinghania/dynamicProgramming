#include<bits/stdc++.h>
using namespace std;
//simply recursive solution
int f(int i,int j,vector<vector<int>>&triangle,int n){
    if(i==n-1) return triangle[i][n-1];
    int d=triangle[i][j]+f(i+1,j,triangle,n);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,n);
    return min(d,dg); 

}
int minimumPathSum(vector<vector<int>>&triangle,int n){
     return f(0,0,triangle,n);
}
//memorisation method
int ff(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
    if(i==n-1) return triangle[i][n-1];
    if(dp[i][j]!=-1) return dp[i][j];
    int d=triangle[i][j]+ff(i+1,j,triangle,n,dp);
    int dg=triangle[i][j]+ff(i+1,j+1,triangle,n,dp);
    return dp[i][j]=min(d,dg);
}
int minimum(vector<vector<int>>&triangle,int n)
{
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return ff(0,0,triangle,n,dp);
}
//Tabulation form
int minimum_path_sum(vector<vector<int>>&triangle,int n){
   vector<vector<int>>dp(n,vector<int>(n,0));
   for(int j=0;j<n;j++){
    dp[n-1][j]=triangle[n-1][j];
   }
   for(int i=n-2;i>=0;i++){
    for(int j=i;j>=0;j--){
        int d=triangle[i][j]+dp[i+1][j];
        int dg=triangle[i][j]+dp[i+1][j+1];
        dp[i][j]=min(d,dg);
    }
   }
   return dp[0][0];
}
int main(){

}