#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&num,int k,int n,vector<int>&dp){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int len=0;
    int max_element=INT_MIN;
    int max_sum=INT_MIN;
    for(int i=ind;i<min(ind+k,n);i++){
        len++;
        max_element=max(max_element,num[i]);
        int sum=len*max_element+f(i+1,num,k,n,dp);
        max_sum=max(max_sum,sum);
    }
    return dp[ind]=max_sum;
}
int maximumSubarray(vector<int>&num,int k){
    int n=num.size();
    // vector<int>dp(n,-1);
    // return f(0,num,k,n,dp);
    //Tabulation
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
    int len=0;
    int max_element=INT_MIN;
    int max_sum=INT_MIN;
    for(int ind=i;i<min(i+k,n);ind++){
        len++;
        max_element=max(max_element,num[i]);
        int sum=len*max_element+dp[ind+1];
        max_sum=max(max_sum,sum); 
    }
    dp[i]=max_sum;
    }
    return dp[0];
}
int main(){

}