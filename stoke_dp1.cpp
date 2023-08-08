#include<bits/stdc++.h>
using namespace std;
// buy and sell onr time
int maximumprofit(vector<int>&prices){
    int mini=prices[0];
    int maxprofit=0;
    int n=prices.size();
    for(int i=1;i<n;i++){
        int cost=prices[i]-mini;
        maxprofit=max(maxprofit,cost);
        mini=min(mini,prices[i]);
    }
    return maxprofit;
}
// buy and sell one or more time unlimited time
long long f(int index,int buy,vector<int>&value,vector<vector<int>>&dp){
    if(index==value.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    long long profit=0;
    if(buy){
        profit=max(-value[index]+f(index+1,0,value,dp),f(index+1,1,value,dp));
    }
    else{
        profit=max(value[index]+f(index+1,1,value,dp),f(index+1,0,value,dp));
    }
    return dp[index][buy]=profit;
}
long long getmaxprofit(vector<int>&value){
    int n=value.size();
    //1 for buy and 0 for sell thats why we are using 2 dimension dp array;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return f(0,1,value,dp);
}
int main(){

}