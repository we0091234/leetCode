#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // vector<int> result;
        // for (int i = 0; i<nums.size();i++)
        // {
        //     for(int j =i+1;j<nums.size();j++)
        //     {
        //         if (nums[i]+nums[j]==target)
        //         {
        //             result.push_back(i);
        //             result.push_back(j);
        //         }
        //     }
        // }
        //    return result;

        vector<int> result;
        map<int,int> myMap;
        for(int i = 0; i<nums.size(); i++)
        {
            if(myMap.find(target-nums[i])!=myMap.end())
            {
                result.push_back(i);
                result.push_back(myMap[target-nums[i]]);
            }
            myMap[nums[i]]=i;
        }
        return result;
    }
};

int main(int argc, char**argv)
{
    vector<int>nums = {3,2,4};
    int target =6;
    Solution solution;
    auto result = solution.twoSum(nums, target);
    for(auto &s:result)
    cout<<s<<endl;
    
    return 0;
}