#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
void show(vector<int> path)
{
    for(auto &s: path)
    cout<<s<<" ";
    cout<<endl;
}
vector<int> path;

void backTrace(vector<int> &nums,int index,vector<vector<int> > &result)
{
    if(path.size()>1 )
    {
        result.push_back(path);
    }
    unordered_set<int> myset;
    for(int i = index; i<nums.size(); i++)
    {
   
        if( (path.size()>0 &&nums[i]<path[path.size()-1])||(myset.find(nums[i])!=myset.end()) )  //保证递增
        continue;
        myset.insert(nums[i]);
        path.push_back(nums[i]);
        backTrace(nums,i+1,result);
        path.pop_back();
    }
}

 vector<vector<int>> findSubsequences(vector<int>& nums) 
 {
    vector<vector<int>> result;
    backTrace(nums,0,result);
    return result;
}

int main(int argc, char** argv)
{
    vector<int> nums{1,2,3,1,1,1,1,1};
    vector<vector<int>>result;
     result=findSubsequences(nums);
     for(auto &son:result)
     show(son);
    return 0;
}