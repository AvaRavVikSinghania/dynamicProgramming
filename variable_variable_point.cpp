#include<bits/stdc++.h>
using namespace std;
//in a matrix you have return maximum path from bottom to top row
//simole recursive soution
int f(int i,int j,vector<vector<int>>&matrix){
    if(j<0 ||j>=matrix[0].size()) return INT_MIN;
    if(i==0) return matrix[i][j];
    int u=matrix[i][j]+f(i-1,j,matrix);
    int ld=matrix[i][j]+f(i-1,j-1,matrix);
    int rd=matrix[i][j]+f(i-1,j+1,matrix);
    return max(u,max(ld,rd));
}
int getmax(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    for(int j=0;j<m;j++){
      maxi=max(maxi,f(n-1,j,matrix));
    }
    return maxi;

}
//dp solution with memorisation
int ff(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(j<0 ||j>=matrix[0].size()) return INT_MIN;
    if(i==0) return matrix[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int u=matrix[i][j]+ff(i-1,j,matrix,dp);
    int ld=matrix[i][j]+ff(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+ff(i-1,j+1,matrix,dp);
    return dp[i][j]=max(u,max(ld,rd));
}
int getmax(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
      maxi=max(maxi,ff(n-1,j,matrix,dp));
    }
    return maxi;

}
//dp with Tabulation format
int maxpathsum(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
           int u=matrix[i][j]+dp[i-1][j];
           int ld=matrix[i][j];
           if(j-1>=0)ld+=dp[i-1][j-1];
           else ld+=INT_MIN;
           int rd=matrix[i][j];
           if(i>1 && j+1<m)rd+=dp[i-1][j+1];
           else rd+=INT_MIN;
           dp[i][j]=max(u,max(ld,rd));
        }
    }
    int maxi=INT_MIN;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
    
}
int main(){

}