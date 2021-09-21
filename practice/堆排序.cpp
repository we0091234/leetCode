#include <iostream>
#include <vector>
using namespace std;
void showArray(vector<int> &nums)
{
    for(auto &s:nums)
    cout<<s<<" ";
    cout<<endl;
}

void heapfy(vector<int> &nums,int len,int parent)
{
    int leftChild = 2*parent+1;
    while(leftChild<len)
    {
    if(leftChild+1<len &&nums[leftChild+1]>nums[leftChild])
    leftChild++;
    if (nums[parent]>nums[leftChild])
    return ;
    swap(nums[parent],nums[leftChild]);
    parent = leftChild;
    leftChild=2*leftChild+1;
    }
}
void buildHeap(vector<int> &nums,int len)
{
    for(int i=(len-2)/2; i>=0; i--)
    heapfy(nums,len,i);
}
void heapSort(vector<int> &nums)  //heapSort
{
    buildHeap(nums,nums.size());
    for(int i = nums.size()-1; i>0; i--)
    {
        swap(nums[0],nums[i]);
        heapfy(nums,i,0);
    }
}

vector<int > topKbig(vector<int> &nums,int k)  //tok最小的值，建立一个大顶堆
{
   buildHeap(nums,k);
   for(int i = k; i<nums.size(); i++)
   {
          if(nums[i]<nums[0])
          {
              swap(nums[i],nums[0]);
              heapfy(nums,k,0);
          }
   }
   return vector<int>(nums.begin(),nums.begin()+k);
}


int main(int argc, char **argv)
{
    vector<int> nums{2,3,1,4,5,6,0,0,0};
    // heapSort(nums);
    auto result = topKbig(nums,4);
    showArray(result);
}