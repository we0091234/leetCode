#include <iostream>
#include <vector>
using namespace std;
vector<int> path;
vector<vector<int>> result;
void show(vector<int> path)
{
    for(auto &s:path)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}
void backTrace(vector<int> &nums,int index,int &max1)
{
    if(path.size()>=1)
    {
        // show(path);
        if(max1 <path.size())
        {
        max1 = path.size();
        }
    }
    for(int i = index; i<nums.size(); i++)
    {
        if(path.size()>=1 && nums[i]<=path[path.size()-1])
        continue;
        
            path.push_back(nums[i]);
            backTrace(nums,i+1,max1);
            path.pop_back();
    }
}

int main(void)
{
    vector<int>nums{7,7,7,7,7,7,7};
    int max1 = 0;
    backTrace(nums,0,max1);
    cout<<max1<<endl;
    return 0;
}