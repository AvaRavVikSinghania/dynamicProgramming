#include<bits/stdc++.h>
using namespace std;
// question is something like that we can not take first and last element  both at a  time and no adjacent element  from the array then find the maximum amount that we can get
int maximum_adjacent(vector<int>&nums){
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1) take+=nums[i-2];
        int nottake=nums[i-1];
        int curri=max(take,nottake);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
long long int houserobber(vector<int>valueinhouse){
    int n=valueinhouse.size();
    if(n==1) return valueinhouse[0];
    vector<int>temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueinhouse[i]);
        if(i!=n-1) temp2.push_back(valueinhouse[i]);
    }
    return max(maximum_adjacent(temp1),maximum_adjacent(temp2));
}
int main(){

}