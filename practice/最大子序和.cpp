#include <iostream>
#include <vector>
#include <algorithm>

int maximumSubsequenceSum(std::vector<int> nums)
{
    std::vector<int> dp(nums.size());
    dp[0]=nums[0];
    for(int i = 1; i<nums.size(); i++)
    {
       dp[i]=std::max(dp[i-1]+nums[i],nums[i]);
    }
    return *std::max_element(dp.begin(),dp.end());
}
int main(void)
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    std::cout<<maximumSubsequenceSum(nums)<<std::endl;
    return 0;
}