#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 int findLengthOfLCIS(vector<int>& nums) {
     vector<int> dp(nums.size());
     dp[0]=1;
     for(int i = 1;i<nums.size();i++) 
     {
         if(nums[i]>nums[i-1])
         dp[i]=dp[i-1]+1;
         else
         dp[i]=1;
     }
     auto iter = max_element(dp.begin(),dp.end());
     return *iter;

    }

int main(int argc, char **argv)
{
    vector<int>nums{2,2,2,2,2};
    cout<<findLengthOfLCIS(nums)<<endl;
    return 0;
}