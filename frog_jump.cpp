#include<bits/stdc++.h>
using namespace std;
// int f(int index,int a[]){
//     if(index==0) return 0;
//     int left=f(index-1,a)+abs(a[index]-a[index-1]);
//     if(index>1)
//     int right=f(index-2,a)+abs(a[index]-a[index-2]);
//     int a=min(left,right);
//     return a;
// }
//memorisation techniques
// int f(int i,vector<int>&heights,vector<int>&dp){
//       if(i==0) return 0;
//       if(dp[i]!=-1) return dp[i];
//       int left=f(i-1,heights,dp)+abs(heights[i]-heights[i-1]);
//       int right=INT_MAX;
//       if(i>1){
//         right=f(i-2,heights,dp)+abs(heights[i]-heights[i-2]);
//       }
//       return dp[i]=min(left,right);
// }
// int frog_jump(int n,vector<int>&heights){
//     vector<int>dp(n+1,-1);
//    return f(n,heights,dp);
//}
//Tabulation method
int f(int i,vector<int>&heights,vector<int>&dp){
      if(i==0) return 0;
      if(dp[i]!=-1) return dp[i];
      int left=f(i-1,heights,dp)+abs(heights[i]-heights[i-1]);
      int right=INT_MAX;
      if(i>1){
        right=f(i-2,heights,dp)+abs(heights[i]-heights[i-2]);
      }
      return dp[i]=min(left,right);
}
int frog_jump(int n,vector<int>&heights){
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1){
            ss=dp[i-2]+abs(heights[i-2]-heights[i]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}
//space optimisation in tabulation method
int frog_jump1(int n,vector<int>&heights){
    int prev1=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int fs=prev1+abs(heights[i]-heights[i-2]);
        int ss=INT_MAX;
        if(i>1){
            ss=prev2+abs(heights[i]-heights[i-2]);
        }
        int ans=min(fs,ss);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
//simple recursion solution
// int f(int i,vector<int>&heights){
//       if(i==0) return 0;
//       int left=f(i-1,heights)+abs(heights[i]-heights[i-1]);
//       int right=INT_MAX;
//       if(i>1){
//         right=f(i-2,heights)+abs(heights[i]-heights[i-2]);
//       }
//       return min(left,right);
// }
// int frog_jump(int n,vector<int>&heights){
//    return f(n,heights);
// }
int main(){
   //sometimes greedy will not work  so we have to 
   // dp
   //greedy takes the present time situation 
   //but  in dp we conclude over all situation and then find best possible path  
   //recursion takes all the possible steps
   vector<int>a={10,20,30,10};
//    cout<<f(4,a);
    cout<<frog_jump(3,a)<<endl;
    cout<<frog_jump1(3,a)<<endl;
   return 0;
}
