#include <iostream>
#include <vector>
using namespace std;
  int minCostClimbingStairs(vector<int>& cost) 
  {
      vector<int> dp(cost.size()+1);
      dp[0]=cost[0];
      dp[1]=cost[1];
      int i = 2;
      for( ; i<cost.size();i++)
      {
          dp[i]=min(dp[i-1],dp[i-2])+cost[i];
      }
      dp[i]=min(dp[i-1],dp[i-2]);
      return dp[i];
  }

int main(void)
{
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairs(cost)<<endl;
    return 0;
}