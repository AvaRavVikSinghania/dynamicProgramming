#include<bits/stdc++.h>
using namespace std;
int f(vector<int>&weight,vector<int>&value,int ind,int w){
    if(ind==0){
        return (w/weight[0])*value[0];
    } 
    int nottake=0+f(weight,value,ind-1,w);
    int take=0;
    if(w>=weight[ind]){
          take=f(weight,value,ind,w-weight[ind]);
    }
    return  max( take ,nottake);
}
int unbound_nap(vector<int>&weight,vector<int>&value,int n,int w){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int W=0;W<=w;W++){
        dp[0][W]=int(W/weight[0])*value[0];
    }
    for(int ind=0;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int nottake=0+dp[ind-1][W];
            int take=0;
            if(weight[ind]<=W){
                take=value[ind]+dp[ind][w-weight[ind]];
            }
            dp[ind][w]=max(take,nottake);
        }
        return dp[n-1][w];
    }
    // space optimisation
    vector<int>prev(w+1,0),curr(w+1,0);
    for(int W=0;W<=w;W++){
        prev[W]=
    }

}
int main(){
    return 0;
}