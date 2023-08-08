#include<bits/stdc++.h>
using namespace std;
int langestsubseq(vector<int>&arr){
    int n=arr.size();
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int index=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[index]=arr[i];
        }

    }
    return temp.size();
}
int main()
{
    vector<int>temp={1,2,3,5,2,4,21,78};
    int n=langestsubseq(temp);
    cout<<n<<endl;
    return 0;
}