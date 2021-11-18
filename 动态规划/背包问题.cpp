
// 背包最大重量为4。

// 物品为：

// 重量	价值
// 物品0	1	15
// 物品1	3	20
// 物品2	4	30
// 问背包能背的物品最大价值是多少？

//解法一：
//二维数组
//1.首先定义dp[i][j]  i代表从0-i取里面取物品，背包重量为j的最大价值为dp[i][j]
//2.递推公式：分为两种情况：1. 如果weight[i]>j的话，那么第i个物品肯定不能放进来，那么dp[i][j]=dp[i-1][j]
//                        2.如果weight[i]<=j的话，那么又分两种情况，第一种情况不放物品i：dp[i][j]= dp[i-1][j]
                                                            //   第二种情况放物品i: dp[i][j]=dp[i-1][j-weight[i]]+value[i]
//解法二：
//一位数组：
//1.首先定义数组dp[j] 代表容量为i的背包，最大价值为dp[j]
//2.确定递推关系 dp[j]=max(dp[j],dp[j-weight[i]]+value[i])



#include <iostream>
#include <vector>
int getMaxValue(std::vector<int>weights,std::vector<int> values,int target)  //二维数组
{
    std::vector<std::vector<int>> dp(weights.size(),std::vector<int>(target+1,0));
    for(int i = 0; i<weights.size(); i++)
    {
        dp[i][0]=0;
    }
    for(int j = 0; j<target+1; j++)
    {
        if(weights[0]<=j)
        dp[0][j]=values[0];
    }
    for(int i = 1; i<weights.size(); i++)
    {
        for(int j =1; j<target+1; j++)
        {
            if(weights[i]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=std::max(dp[i-1][j-weights[i]]+values[i],dp[i-1][j]);
        }
    }
    return dp[weights.size()-1][target];
}

int getValueMaxYiwei(std::vector<int>weights,std::vector<int> values,int target)
{
    std::vector<int> dp(target+1,0);

    for(int i = 0; i<weights.size(); i++)
    {
        for(int j=target;j>=weights[i]; j--)
        {
            dp[j]=std::max(dp[j],dp[j-weights[i]]+values[i]);
        }
    }
    return dp[target];
}

int main(int argc, char **argv)
{
    std::vector<int> weights{1,3,4};
    std::vector<int> values{15,20,30};
   std::cout<< getValueMaxYiwei(weights,values,4)<<std::endl;
    return 0;
}