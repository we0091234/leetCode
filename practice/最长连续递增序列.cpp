#include <iostream>
#include <vector>
#include <algorithm>

int func(std::vector<int>nums)
{
    std::vector<int> dp(nums.size());
    dp[0]=1;
    for(int i = 1; i<nums.size(); i++)
    {
        if(nums[i]>nums[i-1])
        dp[i]=dp[i-1]+1;
        else
        dp[i]=0;
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main(int argc, char **argv)
{
    std::vector<int> nums{1,3,5,4,7};
    std::cout<<func(nums)<<std::endl;

    return 0;
}