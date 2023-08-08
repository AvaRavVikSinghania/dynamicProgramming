#include<bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){

     if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
           if(task!=last){
            maxi=max(maxi,points[0][task]);
           }
        }
     return maxi; 
     } 
     if(dp[day][last]!=-1) return dp[day][last];
     int maxi=0;
     for(int task=0;task<3;task++){
        if(task!=last){
          int point=points[day][task]+f(day-1,task,points,dp); 
          maxi=max(maxi,point); 
        }
     }
     return dp[day][last]=maxi;
}
int ninjaTraining(int n,vector<vector<int>>&points){
    //converting into two dimension dp array
    vector<vector<int>>dp(n,vector<int>(4,-1));
    int n=points.size();
  return f(n-1,3,points,dp);
}
// int f(int day,int last,vector<vector<int>>&points){
//      if(day==0){
//         int maxi=0;
//         for(int task=0;task<3;task++){
//            if(task!=last){
//             maxi=max(maxi,points[0][task]);
//            }
//         }
//      return maxi; 
//      } 
//      int maxi=0;
//      for(int task=0;task<3;task++){
//         if(task!=last){
//           int point=points[day][task]+f(day-1,task,points); 
//           maxi=max(maxi,point); 
//         }
//      }
//      return maxi;
// }
// int ninjaTraining(int n,vector<vector<int>>&points){
//   int n=points.size();
//   return f(n-1,3,points);
// }


//TABULATION
// step-1- declare same size  dp array
//
int ninjaTraining(int n, vector<vector<int>>&point){
    vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(point[0][1],point[0][2]);
    dp[0][1]=max(point[0][0],point[0][2]);
    dp[0][2]=max(point[0][1],point[0][0]);
    dp[0][3]=max(point[0][1],max(point[0][0],point[0][2]));
    for(int day=1;day<n;day++){
         for(int last=0;last<4;last++){
            dp[day][last]=0;
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                 int point1=point[day][task]+dp[day-1][task];
                 dp[day][last]=max(dp[day][last],point1);   
                }
            }

            // dp[day][last]=maxi;
         }
    }
    return dp[n-1][3];
}
// constant space for culculating
int ninjaTraining(int n, vector<vector<int>>&point){
    vector<int>dp(4,0);
    dp[0]=max(point[0][1],point[0][2]);
    dp[1]=max(point[0][0],point[0][2]);
    dp[2]=max(point[0][1],point[0][0]);
    dp[3]=max(point[0][1],max(point[0][0],point[0][2]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
         for(int last=0;last<4;last++){
            temp[last]=0;
            int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                 int point1=point[day][task]+dp[task];
                 temp[last]=max(temp[last],point1);   
                }
            }

            // dp[day][last]=maxi;
         }
         dp=temp;
    }
    //return dp[n-1][3];
     return dp[3];
}
int main(){

}