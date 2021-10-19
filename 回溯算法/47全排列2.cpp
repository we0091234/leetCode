#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void show(vector<int> path)
{
    for (auto &s :path)
    cout<<s<<" ";
    cout<<endl;
}
vector<int> path;
void backTrace(vector<int>&nums,vector<vector<int>> &result,vector<bool> &used) 
{
    if(path.size()==nums.size())
    {
        // show(path);
        result.push_back(path);
        return ;
    }
    unordered_set<int> myset;
    for(int i = 0; i<nums.size(); i++)
    {
        if(used[i]==true || myset.find(nums[i])!=myset.end())
        continue;
        // if(i>0 && nums[i]==nums[i-1])
        // continue;
        path.push_back(nums[i]);
        myset.insert(nums[i]);
        used[i]=true;
        backTrace(nums,result,used);
        path.pop_back();
        used[i]=false;
    }
}


   vector<vector<int>> permute(vector<int>& nums) 
   {
        vector<vector<int>>result;
    vector<bool> used(nums.size(),false);
    backTrace(nums,result,used);
    return result;
 }
int main(int argc, char** argv)
{
    vector<int> nums{1,1,2};
    auto result = permute(nums);
    for(auto &son: result)
    show(son);
    return 0;
}