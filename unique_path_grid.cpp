#include<bits/stdc++.h>
using namespace std;
// int f(int i,int j){
//     if(i==0 && j==0) return 1;
//     if(i<0 ||j<0) return 0;
//     int up=f(i-1,j);
//     int left=f(i,j-1);
//     return up+left;
// }
// int total_unique_path(int m ,int n){
//   return f(m-1,n-1);
// }
int f(int i,int j,vector<vector<int>>&dp){
    if(i==0 && j==0) return 1;
    if(i<0 ||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=f(i-1,j,dp);
    int left=f(i,j-1,dp);
    return dp[i][j]= up+left;
}
int total_unique_path(int m ,int n){
    vector<vector<int>>dp(m,vector<int>(n,-1));
  return f(m-1,n-1,dp);
}
//space optimisation
int totol_path(int m,int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[i][j]=1;
            else{
                int up=0;
                int left=0;
            if(i>1) up=dp[i-1][j];
            if(j>1) left=dp[i][j-1];
            dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}
int UniquePath(int m,int n){
    vector<int>prev(n,0);//column no
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            int up=0;
            int left=0;
            if(i==0 && j==0) temp[j]=1;
            if(j>1) up=prev[j-1];
            if(j>1) left=temp[j];
            temp[j]=up+left;
        }
        prev=temp;
    }
    return prev[n-1];
}
//0(n) solution
int unique(int m,int n){
    int N=n+m-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;i++){
        res=res*(N-r+i)/i;
    }
    return (int)res;
}
int main(){

}