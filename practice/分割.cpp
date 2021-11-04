#include <iostream>
#include <vector>

using namespace std;
void show(vector<int>nums)
{
    for(auto &s:nums)
    cout<<s;
    cout<<" ";
}
vector<vector<int>>path;
void backTrace(vector<int>nums,int index,int &size)
{
    if(size==nums.size())
    {
        for(auto &s:path)
        show(s);
        cout<<endl;
    }
    for(int i =index; i<nums.size(); i++)
    {

        vector<int> tmp(nums.begin()+index,nums.begin()+i+1);
       
        size += tmp.size();
        path.push_back(tmp);
        backTrace(nums,i+1,size);
        path.pop_back();
        size-=tmp.size();
    }
}



int main(int argc, char **argv)
{
    vector<int> nums{1,2,3,4,5};
    // show(nums);
    int size = 0;
    backTrace(nums,0,size);
    return 0;
}