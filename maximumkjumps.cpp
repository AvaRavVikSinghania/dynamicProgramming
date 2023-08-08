//A frog can jumps maximum k jumps we have to culculate minimum effort in doing so
#include<bits/stdc++.h>
using namespace std;
int f(int index,vector<int>&a,int k,vector<int>&dp){
     if(index==0) return 0;
     if(dp[index]!=-1) return dp[index];
     int minstep=INT_MAX;
     for(int j=1;j<=k;j++){
        if(index-j>=0){
        int jump=f(index-j,a,k,dp)+abs(a[index]-a[index-j]);
        minstep=min(minstep,jump);
     }
    }
     return dp[index]= minstep;
}
int jumps(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>dp(n,0);
   // return f(arr.size()-1,arr,k,dp);
   //Tabulation
   dp[0]=0;
   for(int i=1;i<n;i++){
    int minstep=INT_MAX;
    for(int j=1;j<=k;j++){
        if(j-i>=0){
            int jump=dp[i-j]+abs(arr[i]-arr[j]);
            minstep=min(minstep,jump);
        }
    }
    dp[i]=minstep;
   }
   return dp[n-1];
   // we can not optimised further resion being if k is comparable to n so no need to optimisation
}
int main(){

}