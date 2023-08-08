#include<bits/stdc++.h>
using namespace std;
//question is somethig like that we have a string and have to make it other string after performing some deleltion and some insertion on them string
// just find common subsequence and subtract from
// the initial string length that no of operation required to remove and then second string length minus subsequence will give the no of insertion
// add both of them will give answer
int lcs(string s,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]) dp[i][j]=i+dp[i-1][j-1];
            else{
                dp[i][j]=max(dp[i][j-1],dp[j-1][i]);
            }
        }
    }
    return dp[n][m];
} 
int removing( string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    return n+m-2*lcs(str1,str2);
}
int main(){

}