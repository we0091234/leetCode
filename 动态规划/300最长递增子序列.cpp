#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;


   int lengthOfLIS(vector<int>& nums) {
       vector<int> dp(nums.size());
      
       dp[0]=1;
    
       for(int i = 1; i<nums.size(); i++) 
       {
           int j=i-1;
           int maxDp = 0;
           while(j>=0 ) 
           {
               if(nums[i]>nums[j]) 
               {
                   if(maxDp<dp[j])
                   maxDp = dp[j];
               }
               j--;
           }
        
           dp[i]=maxDp+1;
           

       }
       auto iter = max_element(dp.begin(), dp.end());
       return *iter;


    }


    int main(void)
    {
        vector<int>nums{0,1,0,3,2,3};
        cout<<lengthOfLIS(nums)<<endl;
        return 0;
    }