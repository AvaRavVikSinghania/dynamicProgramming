#include<bits/stdc++.h>
using namespace std;
// when number contains 0 also
int f(int i,int sum,vector<int>&num,vector<vector<int>>&dp){
   if(i==0){
    if(sum==0 && num[0]==0) return 2;
    if(sum==0 || sum==num[0]) return 1;
    return 0;
   }
   if(dp[i][sum]!=-1) return dp[i][sum];
   int nottake=f(i-1,sum,num,dp);
   int take=0;
   if(sum<=num[i]) take+f(i-1,sum-num[i],num,dp);
   return dp[i][sum]=take+nottake;
}
int countPartition(int n,int d,vector<int>&arr){
    int totalSum=0;
    for(auto &it:arr){
        totalSum+=it;
    }
    if((totalSum-d)<0 || (totalSum-d)%2) return -1;
    vector<vector<int>>dp(n,vector<int>((totalSum-d)/2+1,-1));
    return f(n-1,(totalSum-d)/2,arr,dp);
}
int main(){

}