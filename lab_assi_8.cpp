#include<bits/stdc++.h>
using namespace std;
struct job{
    char id;
    int dead;
    int profit;
};
bool comparision(job a,job b){
    return (a.profit>b.profit);
}
int max_profit( job arr[],int n){
    sort(arr,arr+n,comparision);
    int result[n];//Storing the result
    bool slot[n];//storing the time slot
    memset(slot,sizeof(bool),false);
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead)-1;j>=0;j--){
           if(slot[i]==false){
            result[j]=i;
            slot[i]=true;
            break;
           }
        }
    }
    // Printing The job That can we scheduled
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[i].id<<" ";
        }
    }
    // Computing the maximum profit
    int max_prt=0;
    for(int i=0;i<n;i++){
        if(slot[i]){
            max_prt+=arr[i].profit;
        }
    }
    return max_prt;
}
//We are using two nested for loop Time complexity will be O(n^2);
//Space complexity will be O(n) for result and O(n) for time slot  So overall space complexity will O(n);
int main(){
    int n;
  cout<<"Enter Total Job = ";
  cin>>n;
  job arr[n];
  cout<<"Enter job details"<<endl;
  for(int i=0;i<n;i++){
     cout<<i+1<<" job detail"<<endl;
     cin>>arr[i].id>>arr[i].profit>>arr[i].dead;
  }
 int max_proFit=max_profit(arr,n);
 cout<<"Maximum Profit = "<<max_proFit<<endl;
 /* 
 5
 a 34 2
 b 23 4
 c 43 2
 d 12 4
 e 43 5
 */ 

  return 0;
}