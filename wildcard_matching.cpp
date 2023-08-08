#include<bits/stdc++.h>
using namespace std;
bool f(int i,string &s, int j,string &t, vector<vector<int>>&dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0 ){
     for(int ii=0;ii<=i;ii++){
        if(s[ii]!='*') return  false;
     }
     return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]|| s[i]=='?'){
     return  dp[i][j]=f(i-1,s,j-1,t,dp);
    }
    if(s[i]=='*'){
     return dp[i][j]= f(i-1,s,j,t,dp)||f(i,s,j-1,t,dp);
    }
    return  dp[i][j]=false;
}
bool match(string s,string t){
     int n=s.size();
     int m=t.size();
     vector<vector<int>>dp(n,vector<int>(m,-1));
     return f(n-1,s,m-1,t,dp);
}
int main(){

}