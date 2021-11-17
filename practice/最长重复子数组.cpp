#include <iostream>
#include <vector>
#include <algorithm>

int func(std::vector<int>nums1,std::vector<int>nums2)
{
    int m = nums1.size()+1;
    int n = nums2.size()+1;
    int maxDp = 0;
    std::vector<std::vector<int>>dp(m,std::vector<int>(n,0));
    for(int i =1; i<m; i++)
    {
        for(int j =1; j<n; j++)
        {
            if(nums2[j-1]==nums1[i-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            dp[i][j]=0;

            if(maxDp<dp[i][j])
            maxDp = dp[i][j];
        }
    }
    return maxDp;
}

int main(int argc, char **argv)
{
    std::vector<int> nums2{1,2,3,2,1};
    std::vector<int>nums1{3,2,1,4,7};
    std::cout<<func(nums1,nums2)<<std::endl;
    // std::cout<<func(nums)<<std::endl;

    return 0;
}