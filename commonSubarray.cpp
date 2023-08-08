#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<int>&arr1,vector<int>&arr2,  vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(arr1[i]==arr2[j] ){
        return 1+f(i-1,j-1,arr1,arr2,dp);
    }
    return dp[i][j]= max(f(i-1,j,arr1,arr2,dp),f(i,j-1,arr1,arr2,dp));
}
int lenth_subaray(vector<int>&arr1,vector<int>&arr2){
     int n=arr1.size();
     int m=arr2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int a =f(n-1,m-1,arr1,arr2,dp);
    int maxi=-1;
    cout<<a<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            maxi=max(maxi,dp[i][j]);
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxi;
}
int main(){
      vector<int>arr1={2,4,7,8,6};
      vector<int>arr2={7,4,7,9,6};
      cout<<lenth_subaray(arr1,arr2);
      return  0;
}