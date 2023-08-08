#include<bits/stdc++.h>
using  namespace std;
 string longestString(vector<string> &words)
    {
        // code here
        map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        string ans="";
        for(int i=1;i<words.size();i++){
             int count=0;
            for(int i=0;i<words[i].size();i++){
                string a=words[i].substr(0,i);
                if(mp.find(a)!=mp.end()) count++;
            }
            if(count==words[i].size()-1){
                if(words[i].size()>ans.size()){
                    ans=words[i];
                }
            }
        }
        return ans;
    }
int main (){

}