#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1000000007;
int f(int i,int j,int istrue,string &exp){
    if(i>j) return 0;
    if(i==j){
        if(istrue==1) return exp[i]=='T';
        else return exp[i]=='F';
    }
    long long  ways=0;
    for(int ind=i+1;ind<=j-1;ind+=2){
       long long LT=f(i,ind-1,1,exp);
       long long LF=f(i,ind-1,0,exp);
       long long RT=f(ind+1,j,1,exp);
       long long RF=f(ind+1,j,0,exp);
       if(exp[ind]=='|'){
        if(istrue){
            ways+=LT*RT+LF*RT+LT*RF;
        }
        else{
            ways=RF*LF;
        }
       }
       else if(exp[ind]=='&'){
        if(istrue){
            ways=LT*RT;
        }
        else{
            ways=LT*RF+LF*RT+LF*RF;
        }
       }
       else{
           if(istrue){
            ways=LT*RF+LF*RT;
           }
           else{
            ways=LT*RT+RF*LF;
           }
       }
    }
    return ways;
}
int booleanExpression(string &str){
     int n=str.size();
     return f(0,n-1,1,str);
}
int evaluateExp(string & exp) {
    int n=exp.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=(exp[i]=='F');
                dp[i][j][1]=(exp[i]=='T');
            }
            else 
            {
                ll ways=0;
                for(ll ind=i+1;ind<=j-1;ind+=2)
                {
                    ll lt=dp[i][ind-1][1]%mod;
                    ll rt=dp[ind+1][j][1]%mod;
                    ll lf=dp[i][ind-1][0]%mod;
                    ll rf=dp[ind+1][j][0]%mod;
                    if(exp[ind]=='&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rf+lf*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rt))%mod;
                    }
                    else if(exp[ind]=='|')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt+lt*rt))%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lt*rt+lf*rf))%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lt*rf+lf*rt))%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}
int main(){

}