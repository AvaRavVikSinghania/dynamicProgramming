//there are infinite coin of same type of different nuumber we can select one or more gind minimum coin
#include<bits/stdc++.h>
using namespace std;
int f(int ind,int T,vector<int>&nums,vector<vector<int>>&dp){
    if(ind==0){
        if(T%nums[0]==0) return T/nums[0];
        return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int nottake=f(ind-1,T,nums,dp);
    int take=1e9;
    if(nums[ind]<=T) take=1+f(ind,T-nums[ind],nums,dp);
    return dp[ind][T]= min(take,nottake);

}
int minimumElement(vector<int>&num,int target){
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
       int ans=f(n-1,target,num,dp);
       if(ans>=1e9) return -1;
       return ans;
}
// Tabulation
int minimumElement(vector<int>&nums,int target){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int T=0;T<=target;T++){
       if(T%nums[0]==0)dp[0][T]=T/nums[0];
       else dp[0][T]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int T=0;T<=target;T++){
        int nottake=dp[i-1][T];
       int take=1e9;
    if(nums[i]<=T) take=1+dp[i][T-nums[i]];
       dp[i][T]= min(take,nottake);

        }
    }
    return dp[n-1][target];
}
int main(){

}