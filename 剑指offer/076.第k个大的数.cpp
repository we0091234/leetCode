#include <iostream>
#include <vector>
using namespace std;
//思路构建容量为k的小顶堆，只要比堆顶元素大就入堆，最后就是k个最大的数，那么栈顶就是第k个最大的数
void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}
void heapfy(vector<int> &nums,int len , int parent)
{
  int leftChild = 2*parent+1;
 while(leftChild<len)
 {
     if(leftChild+1<len && nums[leftChild]>nums[leftChild+1])
     {
         leftChild++;
     }
     if(nums[parent]<nums[leftChild])
     return ;
     swap(nums[parent],nums[leftChild]);
     parent =leftChild;
     leftChild=2*leftChild+1;
 }
}

void buildHeap(vector<int>&arr,int len)
{
    for(int i=(len-2)/2; i>=0; i--)
    {
        heapfy(arr,len,i);
    }
}

int  kthLargestNum(vector<int>&nums,int k)
{
    
    buildHeap(nums,k);
    for(int i=k; i<nums.size(); i++)
    {
        if(nums[0]<nums[i])
        {
            nums[0] = nums[i];
            heapfy(nums,k,0);
        }
    }
    return nums[0];
}

void heapSort(vector<int>&nums)
{
    int len =nums.size();
    buildHeap(nums,len);
    for(int i =len-1; i>0; i--)
    {
        swap(nums[0],nums[i]);
        heapfy(nums,i,0);
    }
}

int main(int argc, char **argv)
{
    vector<int> arr{9,6,5,2,1,4,7,8};
    // show(arr);
    // heapSort(arr);
    // show(arr);
    cout<<kthLargestNum(arr,3)<<endl;
    return 0;
}