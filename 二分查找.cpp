#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int>&array,int val)  //寻找左边界
{
  int left = 0,right = array.size();
  while(left<right)
  {
      int mid =left+((right-left)>>1);   //如果采用(left+right)有可能会产生溢出
      if(array[mid]==val)
      right= mid;
      else if(array[mid]<val)
      left=mid+1;
      else if(array[mid]>val)
      right=mid;
  }

   return left;
}

int main()
{
    vector<int > array{1,2,2,2,3,3,4,5};
    
    cout<<binary_search(array,3)<<endl;
    return 0;
}