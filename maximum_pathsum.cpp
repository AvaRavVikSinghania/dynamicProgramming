#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>&matrix){
    if(j<0||j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    int u=matrix[i][j]+f(i-1,j,matrix);
    int ld=matrix[i][j]+f(i-1,j-1,matrix);
    int rd=matrix[i][j]+f(i+1,j+1,matrix);
    return max(u,max(ld,rd));
}
int getMaxpathsum(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    for(int i=0;i<m;i++){
        maxi=max(maxi,f(n-1,i,matrix));
    }
    return maxi;

}
// dp solution memorisation
int ff(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
    if(j<0||j>=matrix[0].size()) return -1e8;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-10) return dp[i][j];
    int u=matrix[i][j]+ff(i-1,j,matrix,dp);
    int ld=matrix[i][j]+ff(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+ff(i+1,j+1,matrix,dp);
    return dp[i][j]= max(u,max(ld,rd));
}
int getMaxpathSum(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m=matrix[0].size();
    int maxi=-1e8;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<m;i++){
        maxi=max(maxi,ff(n-1,i,matrix,dp));
    }
    return maxi;

}
//tabulation method
int getMaxpathSum(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
     for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
     }
     for(int j=1;j<n;j++){
        for(int i=0;i<m;i++){
            int u=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j];
            if(j-i>=0) ld+=dp[i-1][j-1];
            else ld+=-1e8;
            int rd=matrix[i][j];
            if(j+1<m)rd+=dp[i+1][j+1];
            else{
                rd+=-1e8;
            }
            dp[i][j]=max(u,max(ld,rd));
        }
     }
     int maxi=-1e8;
     for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
     }
}
int main(){

}