#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
void backTrace (vector<int> &nums,int target,int &times,int &sum)
{
    if(sum == target)
    {
        times+=1;
        return ;
    }
    if(sum>target)
    return ;
    for(int i = 0; i<nums.size(); i++)
    {
        sum+=nums[i];
        backTrace(nums,target,times,sum);
        sum-=nums[i];
    }
}
    int combinationSum4(vector<int>& nums, int target) {
        int times=0;
        int sum = 0;
        backTrace(nums,target,times,sum);
        return times;

    }
};

int main(int argc, char** argv)
{
    vector<int> l1{1,2,3};
    // cout<<sumVec(l1)<<endl;
    Solution myslu;
    auto result = myslu.combinationSum4(l1,20);
    cout<<result<<endl;
    return 0;
}