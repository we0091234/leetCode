#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>&array,int val) //找的是靠近中间的那个值
{
    int left = 0,right = array.size()-1;
    while(left<=right)
    {
        int mid = left+((right-left)>>1);
        if(array[mid]==val)
        return mid;
        else if(array[mid]>val)
        right=mid-1;
        else if(array[mid]<val)
        left =mid+1;
    }
    return -1;
}

int binary_searchLeft(vector<int>&array,int val)  //寻找左边界
{
  int left = 0,right = array.size()-1;
  while(left<=right)
  {
      int mid =left+((right-left)>>1);   //如果采用(left+right)有可能会产生溢出
      if(array[mid]==val)
      right= mid-1;
      else if(array[mid]<val)
      left=mid+1;
      else if(array[mid]>val)
      right=mid-1;
  }
  if(left>=array.size() || array[left]!=val)
  return -1;
  return left;
}

int binary_searchRight(vector<int>&array,int val)  //寻找右边界
{
  int left = 0,right = array.size()-1;
  while(left<=right)
  {
      int mid =left+((right-left)>>1);   //如果采用(left+right)有可能会产生溢出
      if(array[mid]==val)
      left= mid+1;
      else if(array[mid]<val)
      left=mid+1;
      else if(array[mid]>val)
      right=mid-1;
  }

    if(right<0||array[right]!=val)
    return -1;
    return right;
}



int main()
{
    vector<int > array{1,2,2,2,3,3,4,5};
    
    cout<<binary_searchRight(array,2)<<endl;
    return 0;
}