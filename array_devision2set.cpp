#include<bits/stdc++.h>
using namespace std;
bool f(int i,int target,vector<int>&arr){
    if(target==0) return true;
    if(i==0){
        return target==arr[0];
    }
    int nottake=f(i-1,target,arr);
    int take=false;
    if(target>=arr[i]) take=f(i-1,target-arr[i],arr);
    return nottake|take;
}
bool division(vector<int>&arr){
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum%2!=0) return false;
    int n=arr.size();
    return f(n-1,sum/2,arr);
}
bool ff(int i,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return true;
    if(i==0){
        return target==arr[0];
    }
    if(dp[i][target]!=-1) return dp[i][target];
    int nottake=ff(i-1,target,arr,dp);
    int take=false;
    if(target>=arr[i]) take=ff(i-1,target-arr[i],arr,dp);
    return dp[i][target]= nottake|take;
}
bool division1(vector<int>&arr){
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum%2!=0) return false;
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
    return ff(n-1,sum/2,arr,dp);
}
// space optimisation
bool devision2(vector<int>&arr){
    int sum=0;
    for(auto it:arr){
        sum+=it;
    }
    if(sum%2!=0) return false;
    int n=arr.size();
    vector<bool>prev(sum/2+1,0),cur(sum/2+1,0);
    prev[0]=cur[0]=true;
    prev[arr[0]]=true;

}
int main(){

}