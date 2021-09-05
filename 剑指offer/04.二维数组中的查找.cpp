#include <iostream>
#include <vector>
using namespace std;
bool binary_search(vector<int> nums,int target)
{
    int left=0,right = nums.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)>>1);
        if(nums[mid]==target)
        return true;
        else if(target>nums[mid])
        left=left+1;
        else if(target<nums[mid])
        right=right-1;
    }
    return false;
}
 bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
  {
    for(int i = 0; i<matrix.size(); i++)
    {
        if(binary_search(matrix[i],target))
        return true;
    }
    return false;
    }
int main(int argc, char **argv)
{
    vector<vector<int>> arrays{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
  cout<<findNumberIn2DArray(arrays,1)<<endl;
    return 0;
}