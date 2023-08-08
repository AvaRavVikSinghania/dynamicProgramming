#include<bits/stdc++.h>
using namespace std;
vector<int>culculateLeftSmaller(vector<int>&height){
     int n=height.size();
     vector<int>leftsmaller;
     leftsmaller.push_back(0);
     stack<int>st;
     st.push(0);
     for(int i=1;i<n;i++){
        if(height[i]>height[st.top()]){
            leftsmaller.push_back(i);
        }else{
            while(!st.empty() && height[i]<=height[st.top()]){
                st.pop();
            }
            if(st.empty()) leftsmaller.push_back(0);
            else{
                leftsmaller.push_back(st.top()+1);
            }
            st.push(i);
        }
     }
     return leftsmaller;
}
vector<int>culculateRightSmaller(vector<int>&height){
     int n=height.size();
     vector<int>rightsmaller;
    rightsmaller.push_back(n-1);
     stack<int>st;
     st.push(n-1);
     for(int i=n-2;i>=0;i--){
        if(height[i]>height[st.top()]){
           rightsmaller.push_back(i);
        }else{
            while(!st.empty() && height[i]<=height[st.top()]){
                st.pop();
            }
            if(st.empty()) rightsmaller.push_back(n-1);
            else{
               rightsmaller.push_back(st.top()-1);
            }
            st.push(i);
        }
     }
     return rightsmaller;
}
int max_area(vector<int>&height){
    int n=height.size();
    vector<int>leftsmaller=culculateLeftSmaller(height);
    vector<int>rightsmaller=culculateRightSmaller(height);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,(abs(leftsmaller[i]-rightsmaller[i])+1)*height[i]);
    }
    return ans;
}
int main(){
    return 0;
}