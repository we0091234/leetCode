#include<iostream>
#include<vector>

using namespace std;

 int findLength(vector<int>& nums1, vector<int>& nums2) 
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
         dp[i][j]=0;

         if(maxEle<dp[i][j])
         maxEle=dp[i][j];
         }
     }

     return maxEle;

    }
int main(int argc, char** argv)
{
    vector<int>nums1{3,2,1,4,7};
    vector<int>nums2{1,2,3,2,1};
    cout<<findLength(nums1,nums2)<<endl;
    return 0;
}