#include <iostream>
#include <vector>
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
        show(path);
        result.push_back(path);
        return ;
    }
    for(int i = 0; i<nums.size(); i++)
    {
        if(used[i]==true)
        continue;
        path.push_back(nums[i]);
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
    vector<int> nums{1,2,3};
    
    return 0;
}