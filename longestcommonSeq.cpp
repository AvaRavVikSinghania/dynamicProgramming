#include<bits/stdc++.h>
using namespace std;
//longest common subsequence
int f(int index,int prev_index,vector<int>&arr,int n,vector<vector<int>>&dp){
    if(index==n) return 0;
    int len=0+f(index+1,prev_index,arr,n,dp);
    if(prev_index==-1||arr[index]>arr[prev_index]){
        len=max(len,1+f(index+1,index,arr,n,dp));
    }
    return len;
}
int length_subsequence(vector<int>&arr){
    int n=arr.size();
    //n+1 due to index sifting
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return f(0,-1,arr,n,dp);
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
            int len=dp[ind+1][prev_ind+1];
            if(prev_ind==-1|| arr[ind]>arr[prev_ind]){
                len=max(len,1+dp[ind+1][ind+1]);
            }
            dp[ind][prev_ind]=len;
        }
    }
   // return dp[0][0];
    //binary search
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]=arr[i];
        }
    }
   return temp.size();
}

int main(){

}