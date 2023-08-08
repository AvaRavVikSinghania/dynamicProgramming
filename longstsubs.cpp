//no of longest subsequnce
//lecture 47 see again
#include<bits/stdc++.h>
using namespace std;
int f(int index,int preindex,vector<int>&arr,vector<vector<int>>&dp){
           if(index==arr.size()) return  0;
           if(dp[index][preindex+1]!=-1) return dp[index][preindex+1];
           int len=f(index+1,preindex,arr,dp);
           if(preindex==-1 || arr[index]>arr[preindex]){
            len=max(len,1+f(index+1,index,arr,dp));
           }
           return  dp[index][preindex+1]=len;

}
int longestsub(vector<int>&arr){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(0,-1,arr,dp);
}
int main(){

}