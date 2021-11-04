#include <iostream>
#include <vector>
using namespace std;
int leftBinarySearch(vector<int> nums,int target)
{
    int left = 0,right= nums.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)>>1);
        if(nums[mid]<target)
        left=mid+1;
        else if(nums[mid]>target)
        right=mid-1;
        else
        right=mid-1;
    }
    if(left>=nums.size()||nums[left]!=target)
    return -1;
    return left;
}

int rightBinarySearch(vector<int> nums,int target)
{
    int left = 0,right= nums.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)>>1);
        if(nums[mid]<target)
        left=mid+1;
        else if(nums[mid]>target)
        right=mid-1;
        else
        left=mid+1;
    }
    if(right<0||nums[right]!=target)
    return -1;
    return right;
}

int main(int argc, char **argv)
{
    vector<int>nums{5,7,7,8,8,8};
   cout<<leftBinarySearch(nums,8)<<endl;
   cout<<rightBinarySearch(nums,8)<<endl;
    return 0;
}