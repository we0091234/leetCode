#include <iostream>
#include <vector>
using namespace std;

int binary_searchLeft(vector<int>&nums,int target)
{
    int left = 0,right = nums.size()-1;
    while(left<=right)
    {
        int mid=left+((right-left)>>1);
        if(nums[mid]==target)
        right=mid-1;
        else if(target>nums[mid])
        left =left+1;
        else if(target<nums[mid])
        right=mid-1;
    }
    if(left>=nums.size()||nums[left]!=target)
     return -1;
    return left;
}


int binary_searchRight(vector<int>&nums,int target)
{
       int left = 0,right = nums.size()-1;
    while(left<=right)
    {
        int mid=left+((right-left)>>1);
        if(nums[mid]==target)
        left=left+1;
        else if(target>nums[mid])
        left =left+1;
        else if(target<nums[mid])
        right=mid-1;
    }
    if(right<0||nums[right]!=target)
     return -1;
    return right;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int>result;
    int left = binary_searchLeft(nums,target);  //先找左边
    int right =binary_searchRight(nums,target);//再找右边
     result.push_back(left);
     result.push_back(right);
     return result;
}
void showNums(vector<int>&nums)
{
    for(auto &s:nums)
    cout<<s<<" ";
}

int main(int argc, char** argv)
{
    vector<int >nums{1};
    auto nums1 = searchRange(nums,1);
   showNums(nums1);
    return 0;
}