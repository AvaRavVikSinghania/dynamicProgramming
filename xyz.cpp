#include<bits/stdc++.h>
using namespace std;
bool f(int i,bool check,vector<int>&num,int k){
   if(i==num.size()){
    return 0;
   }

   if(check){
       int number=num[i];
       int take1=0;
       int take2=0;
       int take3=f(i+1,check,num,k);
       if(number%2==0){
          take1=num[i]+f(i+1,check,num,k);
       }else{
          take2=num[i]-k+f(i+1,!check,num,k);
       }
       return max(take1,max(take2,take3));
   }else{
       int number=num[i];
       int take1=0;
       int take2=0;
       int take3=f(i+1,check,num,k);
       if(number%2==1){
          take1=num[i]+f(i+1,check,num,k);
       }else{
          take2=num[i]-k+f(i+1,!check,num,k);
       }
       return max(take1,max(take2,take3));
   }
}
int f(vector<int>&num,int k){
     
}
int main(){

}