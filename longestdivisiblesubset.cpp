#include<bits/stdc++.h>
using namespace std;
vector<int> lengthsubsequence(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int>dp(n,-1),hash(n);
    int maxi=1;
    int lastindex=0;
    for(int i=1;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[prev]%arr[i]==0 && 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        temp.push_back(lastindex);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
int main(){
      
}