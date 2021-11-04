#include<iostream>
#include<vector>
#include <set>

using namespace std;

 int findLength(string nums1, string nums2) 
 {
     int m = nums1.size()+1;
     int n = nums2.size()+1;
     int maxEle= 0;
     vector<vector<int>>dp(m,vector<int>(n,0));
     
     for(int i = 1; i<m;i++)
     {

         for(int j =1; j<n; j++)
         {
             
         if(nums1[i-1]==nums2[j-1])
         {
             dp[i][j]=dp[i-1][j-1]+1;
         }
         else
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
         if(maxEle<dp[i][j])
         maxEle=dp[i][j];
         }
     }

     return maxEle;

    }
int main(int argc, char** argv)
{
  string st2 = "bsbininm";
  string st1 ="jmjkbkjkv";
  

    cout<<findLength(st1,st2)<<endl;
    return 0;
}