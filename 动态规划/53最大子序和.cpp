#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


    int maxSubArray(vector<int>& nums) 
    {
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            if(nums[i]+dp[i-1]>nums[i])
            dp[i]=nums[i]+dp[i-1];
            else
            dp[i]=nums[i];
        }
        auto iter = max_element(dp.begin(), dp.end());
        return *iter;

    }

int main(int argc, char **argv)
{
    vector<int>nums{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}