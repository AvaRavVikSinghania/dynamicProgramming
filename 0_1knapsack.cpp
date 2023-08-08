#include<bits/stdc++.h>
using namespace std;
int f(int ind,int w,vector<int>&weight,vector<int>&value, vector<vector<int>>&dp){
    if(ind==0){
        if(weight[0]<=w) return value[0];
        return 0;
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int nottake=f(ind-1,w,weight,value,dp);
    int take=INT_MIN;
    if(w>=weight[ind])take+=f(ind-1,w-weight[ind],weight,value,dp);
    return  dp[ind][w]= max(nottake,take);
}
int knapsack(vector<int>weight,vector<int>value,int n,int maximumWeight){
    vector<vector<int>>dp(n,vector<int>(maximumWeight+1,-1));
      return f(n-1,maximumWeight,weight,value,dp);
}
int knapsack2(vector<int>weight,vector<int>value,int n,int maximumWeight){
    vector<vector<int>>dp(n,vector<int>(maximumWeight+1,0));
    for(int w=0;w<=maximumWeight;w++) dp[0][w]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=maximumWeight;w++){
     int nottake=dp[ind-1][w];
    int take=INT_MIN;
    if(w>=weight[ind])take+=dp[ind-1][w-weight[ind]];
    dp[ind][w]= max(nottake,take);
        }
    }
    return dp[n-1][maximumWeight];
}
int main(){

}