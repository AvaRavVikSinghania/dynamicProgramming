#include<bits/stdc++.h>
using namespace std;
int count(int i,int value,int a[]){
    if(i==0){
        return (value%a[i]==0);
    }  
    int nottake=count(i-1,value,a);
    int take=0;
    if(a[i]<=value){
        take=count(i,value-a[i],a);
    }
    return take+nottake;
}
long countwaytomake_change(int demo[],int n,int value){
    //    count(n-1,value,demo);
    //tabulation
    //    vector<vector<int>>dp(n,vector<int>(value+1,0));
    //    for(int i=0;i<=value;i++){
    //         dp[0][i]=(i%demo[0]==0);
    //    }
    //    for(int i=1;i<n;i++){
    //     for(int t=0;t<=value;t++){
    //         int nottake=dp[i-1][t];
    //         int  take=0;
    //         if(demo[i]<=t){
    //             take=dp[i][t-demo[i]];
    //         }
    //         dp[i][t]=take+nottake;
    //     }
    //    }
    //    return dp[n-1][value];
    // space optimisation
    vector<int>prev(value+1,0),curr(value+1,0);
    for(int t=0;t<=value;t++){
        prev[t]=t%demo[0]==0;
    }
    for(int ind=1;ind<=n;ind++){
        for(int t=0;t<=value;t++){
            int nottake=prev[t];
            int take=0;
            if(demo[ind]<=t){
                take=curr[t-demo[ind]];
            }
            curr[t]=nottake+take;
        }
        prev=curr;
    }
    return prev[value];
}
int main(){
          int arr[]={1,2,3};
          cout<<countwaytomake_change(arr,3,4);

   return 0;
}