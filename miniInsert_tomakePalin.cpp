#include<bits/stdc++.h>
using namespace std;
// Given a string  we have to make it palindrome by inserting some character in it
// approach is find out langest palindrome and substract  from the length
int f(int i,string s,int j,string t,vector<vector<int>>&dp){
    if(i<0 ||j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j])  return dp[i][j]=1+f(i-1,s,j-1,t,dp);
    return dp[i][j]=max(f(i-1,s,j,t,dp),f(i,s,j-1,t,dp));
}
int palindrome(string s){
    int n=s.size();
    string t=s;
    reverse(s.begin(),s.end());
  vector<vector<int>>dp(n,vector<int>(n,-1));
  return n-f(n-1,s,n-1,t,dp);
}
int main(){
    cout<<palindrome("abcaa");
    return 0;
}