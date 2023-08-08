#include<bits/stdc++.h>
using namespace std;
int f(int i,vector<int>&arr,int sum,vector<vector<int>>&dp){
    if(sum==0) return 1;
    if(i==0){
        return sum==arr[i];
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int nottake=f(i-1,arr,sum,dp);
    int take=0;
    if(arr[i]<=sum){
        take+=f(i-1,arr,sum-arr[i],dp);
    }
    return  dp[i][sum]=take+nottake;
}
int count(vector<int>&arr,int sum){
    vector<vector<int>>dp(arr.size()-1,vector<int>(sum+1,-1));
    return f(arr.size()-1,arr,sum,dp);
}
//tabulation
int findways(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(arr[0]<=target) dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=target;sum++){
            int nottake=dp[i-1][sum];
            int take=0;
            if(sum>=arr[i]) take+=dp[i-1][sum-arr[i]];
            dp[i][sum]=take+nottake;
        }
    }
    return dp[n-1][target];


}
int main(){

}