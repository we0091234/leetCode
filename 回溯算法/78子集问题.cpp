#include <iostream>
#include <vector>
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
    if(path.size()>0)
    {
        result.push_back(path);
    }
    for(int i = index; i<nums.size(); i++)
    {
        path.push_back(nums[i]);
        backTrace(nums,i+1,result);
        path.pop_back();
    }
}

 vector<vector<int>> subsets(vector<int>& nums) 
 {
    vector<vector<int>> result;
    vector<int> nullJihe;
    result.push_back(nullJihe);
    backTrace(nums,0,result);
    return result;
}

int main(int argc, char** argv)
{
    vector<int> nums{1,2,3};
    vector<vector<int>>result;
     backTrace(nums,0,result);
    return 0;
}