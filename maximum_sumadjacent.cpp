#include<bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&nums){
    if(index==0) return 0;
    if(index<0) return 0;
    int pick=nums[index]+f(index-2,nums);
    int notpick=0+f(index-1,nums);
    return max(pick,notpick);
}
int maximumnonadjacentSum(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums);
}
int f(int index,vector<int>&nums,vector<int>&dp){
    if(index==0) return 0;
    if(index<0) return 0;
    if(dp[index]!=-1) return dp[index];
    int pick=nums[index]+f(index-2,nums);
    int notpick=0+f(index-1,nums);
    return dp[index]=max(pick,notpick);
}
int maximumnonadjacentSum(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}
//  stack space optimisation 
int maximum(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=nums[i-2];
        int nottake=nums[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}
// space optimisation with o(1) space
int maximum_sum(vector<int>&nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=nums[i-2];
        int nottake=0+prev;
        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
int main(){

}