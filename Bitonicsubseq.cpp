#include<bits/stdc++.h>
using namespace std;
int langestbitonic(vector<int>&arr){
    int n=arr.size();
    vector<int>dp1(n,0);
    vector<int>dp2(n,0);
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[prev]<arr[i] && 1+dp1[prev]<dp1[i]){
                dp1[i]=1+dp1[prev];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--){
            if(arr[prev]<arr[i] && 1+dp2[prev]<dp1[i]){
                dp2[i]=1+dp2[prev];
            }
        }
    }
    int maxi=-1;
    for(int i=0;i<n;i++){
      maxi=max(maxi,dp1[i]+dp2[i]);
    }
    return maxi-1;
}
int main(){

     return 0;
}