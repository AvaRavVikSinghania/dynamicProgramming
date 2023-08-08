#include<bits/stdc++.h>
using namespace std;
vector<int>prefix_function(string s){
  int n=s.size();
  vector<int>pi(n);
  for(int i=0;i<n;i++){
    for(int k=0;k<=i;k++){
        if(s.substr(0,k)==s.substr(i-k+1,k)){
            pi[i]=k;
        }
    }
  }
  return pi;
  //tc o(n^3)
}
vector<int>optimisedprefix_d_function(string s){
    int n=s.size();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
}
vector<int>KMP_algorithm(string text,string pattern){   
    vector<int>ans;
    int n=pattern.size();
    vector<int>prefix=optimisedprefix_d_function(pattern);
    int i(0),j(0);
    while(i<text.size()){
        if(text[i]==pattern[j]){
           i++,j++;
        }
        else{
            if(j!=0){
                j=prefix[j-1];
            }
            else{
                i++;
            }
        }
        if(j==pattern.size()){
          ans.push_back(i-pattern.size());
          j=0;
        }
    }
    return ans;
}
int main(){
     int i=0,j=0;
     
}