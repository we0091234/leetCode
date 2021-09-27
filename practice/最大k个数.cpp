//思路 最大k个数可以构键小顶堆

#include<iostream>
#include <vector>
#include <queue>
using namespace std;
void show(vector<int> &nums)
{
        for(auto &s:nums)
        cout<<s<<" ";
        cout<<endl;
}
void heapfy(vector<int>& nums,int len,int parent)  //将一个有孩子节点的节点堆化
{
     //首先找到当前点的左孩子节点
     int leftChild = 2*parent+1;
    //  int tmp = nums[parent];
     while(leftChild < len)
     {
         if(leftChild+1<len && nums[leftChild]>nums[leftChild+1]) //小顶堆 判断哪个最小
         leftChild++;
         if(nums[parent]<nums[leftChild])
         return ;
         swap(nums[parent] ,nums[leftChild]);
         parent =leftChild;
         leftChild=2*leftChild+1;
     }
  

}
void buildHeap(vector<int> &nums,int len)
{
   for(int i =(len-2)/2; i>=0; i--)
   {
       heapfy(nums,len,i);
   }
}
vector<int> findTopK(vector<int>&nums,int k)  //前k个数建立一个小顶堆，然后从k+1个开始，和堆顶元素比较，如果比堆顶元素还小，那么最小堆不变，如果比最小堆堆顶还打，那么这个数入堆，并对堆顶元素就行heapfy
{
    buildHeap(nums,k);    //前k个元素建立一个小顶堆
    for(int i = k;i<nums.size(); i++) //从第k+1个元素开始，逐一与小顶堆元素比较
    {
       if(nums[i]>nums[0])      //如果大于堆顶，那就替换堆顶
       {
         nums[0]=nums[i];
         heapfy(nums,k,0);     //并且heapfy堆顶元素
       }
    }
    return vector<int>(nums.begin(),nums.begin()+k);
}
void heapSort(vector<int> &nums)
{
    buildHeap(nums,nums.size());
    show(nums);
    for(int i = nums.size()-1; i>0; i--)
    {
        swap(nums[i],nums[0]);
        heapfy(nums,i,0);
    }
}
vector<int>  findTopKsmall(vector<int> &nums,int k)
{
    vector<int> result;
    priority_queue<int,vector<int> ,less<int> > myqueue;
    for(int i = 0; i<k; i++)
    {
        myqueue.push(nums[i]);
    }
    for(int i = k; i<nums.size(); i++)
    {
        int top = myqueue.top();
        if(top >nums[i] )
        {
            myqueue.pop();
            myqueue.push(nums[i]);
        }
    }
    
    while(!myqueue.empty())
    {
        result.push_back(myqueue.top());
        myqueue.pop();
    }
    return result;
    
}

int main(int argc, char **argv)
{
    vector<int > array{9,9,9,9,5,1,0,12};
    show(array);
    // auto newArray = findTopK(array,5);
    // show(newArray);
     auto result = findTopKsmall(array,4);
    show(result);
    return 0;
}