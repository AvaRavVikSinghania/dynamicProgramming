//Given a array in which we have assign - and + sign to  value such that there differnt is target
#include<bits/stdc++.h>
using namespace std;
bool f(int i,int target,vector<int>&arr){
    if(target==0) return true;
    if(i==0){
        if(target==arr[0]) return true;
        return false;
    }
    int nottake=f(i-1,target,arr);
    int take=0;
    if(target<=arr[i]) take=f(i-1,target-arr[i],arr);
    return take||nottake;
}
bool partition(int n,int target,vector<int>&arr){
    int totalSum=0;
    for(int it:arr){
        totalSum+=it;
    }
    if(totalSum-target<0||(totalSum-target)%2!=0) return false;
    else return f(n-1,target,arr);
}
int main(){

}
