#include<bits/stdc++.h>
using namespace std;
int minimumSumDiff(vector<int>&arr,int n){
    int total_sum=0;
    for(auto it:arr){
        total_sum+=it;
    }
    int k=total_sum;
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int i=0;i<n;i++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[i-1][target];
            bool take=false;
            if(arr[i]<=target) take=dp[i-1][target-arr[i]];
            dp[i][target]=take|nottake;
        }
    }
  int mini=1e8;
  for(int s1=0;s1<=k/2;s1++){
    if(dp[n-1][s1]){
        mini=min(mini,abs((k-s1)-s1));
    }
  }
  return mini;
}
int main(){
    return 0;
}