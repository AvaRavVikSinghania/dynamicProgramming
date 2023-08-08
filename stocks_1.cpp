#include<bits/stdc++.h>
using namespace std;
// buy and sell only be one
int max_profit(vector<int>&stock,int n){
    int mini=stock[0];
    int maxprofit=0;
    for(int i=1;i<n;i++){
        int cast=stock[i]-mini;
        maxprofit=max(maxprofit,cast);
        mini=min(mini,stock[i]);
    }
    return maxprofit;
}
int main(){

}