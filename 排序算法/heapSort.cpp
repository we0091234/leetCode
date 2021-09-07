#include <iostream>
#include <vector>
using namespace std;
//显示数组
void show(vector<int> &nums)
{
        for(auto &s:nums)
        cout<<s<<" ";
        cout<<endl;
}
void  heapfy(vector<int> &nums,int len,int index)  //将一个index从上到下，进行heapfy，heapfy作用是让父节点大于子节点
{
    int leftChild = 2*index+1;
    // int len = nums.size();
    while(leftChild < len)
    {
        if(leftChild+1<len && nums[leftChild+1]<nums[leftChild])
        leftChild = leftChild+1;
        if(nums[index] <=nums[leftChild])
        return ;
        swap(nums[index],nums[leftChild]);
        index =leftChild;
        leftChild=2*leftChild+1;
    }
    // nums[leftChild]=tmp;
}
void buildHeap(vector<int> &nums)  //将所有非叶子节点进行heapfy，从下到上，第一个非叶子节点是 (len-2)/2;
{
    int len = nums.size();
    for(int i = (len-2)/2; i>=0; i--)
    {
             heapfy(nums,nums.size(),i);
    }
}
void heapSort(vector<int> &nums) // 堆排序
{
    buildHeap(nums);  //首先建立一个堆
    int len = nums.size();
    for(int i = len-1; i>0; i--)
    {
        swap(nums[i],nums[0]);
        heapfy(nums,i,0);
    }
}

int main()
{
    vector<int > array{4,3,7,5,2,6,1};
    show(array);
    heapSort(array);
    show(array);
    return 0;
}