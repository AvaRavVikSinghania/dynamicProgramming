//tabulation bottom up
//memorisation top down
//memorisation-tend to store the value of subproblem in some map/table
//
#include<bits/stdc++.h>
using namespace std;
//memorisation
// int f(int n,vector<int>&dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//      return dp[n]=f(n-1,dp)+f(n-2,dp);
// }
int main(){
int n=5;
//      vector<int>dp(n+1,-1);
//      cout<<f(n,dp);
//      return 0;
// }
//
//Time complexity O(n)
//Space complexity O(n)+O(n) array for dp;

// Tabulation method has space complexity o(n) and time complexity O(n)
int dp[n+1];
 dp[0]=0,dp[1]=1;
 for(int i=2;i<=n;i++){
  dp[i]=dp[i-1]+dp[i-2];
 }
// cout<<dp[i];
return 0;
}
