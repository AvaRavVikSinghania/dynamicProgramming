#include<bits/stdc++.h>
using namespace std;
//simple recurrsion
int f(int i,int j,vector<vector<int>>grid){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 ||j<0) return INT_MAX;
    int up=grid[i][j]+f(i-1,j,grid);
    int left=grid[i][j]+f(i,j-1,grid);
    return min(up,left);
}
int minimumPath(vector<vector<int>>&grid){
  int n=grid.size();
  int m=grid[0].size();
  return f(n-1,m-1,grid);
}
//using dp 1-memorisation
int ff(int i,int j,vector<vector<int>>grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 ||j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int up= grid[i][j]+ff(i-1,j,grid,dp);
    int left= grid[i][j]+ff(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);

}
int minimunpath(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return ff(m-1,n-1,grid,dp);
}
//Tabultion form
int minimumPathSum(vector<vector<int>>&grid){
  int n=grid.size();
  int m=grid[0].size();
  vector<vector<int>>dp(m,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i==0 && j==0) dp[i][j]=grid[i][j];
        else{
            int up=0;
            int left=0;
            if(i>1) up=grid[i][j]+dp[i-1][j];
            if(j>1) left=grid[i][j]+dp[i][j-1];
            dp[i][j]=min(up,left);
        }
    }
    return dp[n-1][m-1];
  }
} 
int main(){

}