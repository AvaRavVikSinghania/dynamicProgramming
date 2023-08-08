#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<int>&cuts){
    if(i>j) return 0;
    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,ind-1,cuts)+f(ind+1,j,cuts);
        mini=min(mini,cost);
    }
    return mini;
}
int minimuncost(int n,int c,vector<int>&cuts){
    cuts.push_back(n);
    cuts.push_back(0);
    cuts.insert(cuts.begin(),0);
    vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
    return f(1,c,cuts);
}
int main(){

}