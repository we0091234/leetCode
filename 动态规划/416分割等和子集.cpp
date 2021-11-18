//https://leetcode-cn.com/problems/partition-equal-subset-sum/
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200
// 示例 1: 输入: [1, 5, 11, 5] 输出: true 解释: 数组可以分割成 [1, 5, 5] 和 [11].
// 示例 2: 输入: [1, 2, 3, 5] 输出: false 解释: 数组不能分割成两个元素和相等的子集.

//1确定dp[j] 表示背包容量为j的最大子和为dp[j]


#include <iostream>
#include <vector>
bool canPartition(std::vector<int>& nums)
 {
    int sum = 0;
    for(auto &s:nums)
    sum+=s;
    if(sum%2!=0)
    return false;
    int val = sum/2;
    std::vector<int> dp(100001,0);
    for(int i = 0; i<nums.size(); i++) //遍历物品
    {
        for(int j = val;j>=nums[i];j--)
        {
            dp[j]=std::max(dp[j],dp[j-nums[i]]+nums[i]);
        }
    
    }
    if(dp[val]==val)
        return true;
   return false;

}
int main(int argc, char **argv)
{
    std::vector<int> nums{1,5,11,5,1};
    std::cout<<canPartition(nums)<<std::endl;
    return 0;
}