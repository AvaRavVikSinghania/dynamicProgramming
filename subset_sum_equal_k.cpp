#include<bits/stdc++.h>
using namespace std;
bool f(int i,int target,vector<int>&arr){
    if(target==0) return true;
    if(i==0) return arr[0]==target;
    bool notatake=f(i-1,target,arr);
    bool take=false;
    if(arr[i]<=target){
        take=f(i-1,target-arr[i],arr);
    }
    return take|notatake;
}
// dp solution with memorisation
bool ff(int i,int target,vector<int>&arr, vector<vector<int>>&dp){
    if(target==0) return true;
    if(i==0) return arr[0]==target;
    if(dp[i][target]!=-1) return dp[i][target];
    bool notatake=ff(i-1,target,arr,dp);
    bool take=false;
    if(arr[i]<=target){
        take=ff(i-1,target-arr[i],arr,dp);
    }
    return dp[i][target]= take|notatake;
}
bool subsetSum(int n,int k,vector<int>&arr){
    return f(n-1,k,arr);
}
bool subsetSum(int n,int k,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return ff(n-1,k,arr,dp);
}
//tabulation method
bool subset(int n,int k,vector<int>&arr){
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
       dp[i][0]=true;
    }
    dp[0][k]=true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
           bool notatake=dp[i-1][target];
          bool take=false;
         if(arr[i]<=target){
         take=dp[i-1][target-arr[i]];
           }
           dp[i][target]=take|notatake;  
        }
    }
    return dp[n-1][k];
}
int main(){

}