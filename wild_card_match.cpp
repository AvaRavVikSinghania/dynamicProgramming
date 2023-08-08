#include<bits/stdc++.h>
using namespace std;
bool f(int i,int j,string pattern,string text){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        for(int ii=0;ii<i;ii++){
            if(pattern[i]!='*') return false;
        }
        return true;
    }
    if(pattern[i]==text[j]||pattern[i]=='?'){
        return f(i-1,j-1,pattern,text);
    }
    if(pattern[i]=='*'){
        return f(i-1,j,pattern,text)|f(i,j-1,pattern,text);
    }
    return false;
}
bool wild_card_match(string pattern,string text){
    int n=pattern.size();
    int m=text.size();
   // return f(n-1,m-1,pattern,text);
   vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
   dp[0][0]=true;
   for(int j=1;j<=m;j++){
    dp[0][j]=false;
   }
   for(int i=1;i<=n;i++){
    bool flag=true;
    for(int ii=1;ii<=i;ii++){
        if(pattern[ii-1]!='*'){
          flag=false;
        }
    }
    dp[i][0]=flag;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
       if(pattern[i-1]==text[j-1]||pattern[i-1]=='?'){
        dp[i][j]=dp[i-1][j-1];
    }
   else  if(pattern[i-1]=='*'){
        dp[i][j]=dp[i-1][j]|dp[i][j-1];
    }
    else dp[i][j]= false;  
    }
   }
  return dp[n][m];
}
int main(){

}