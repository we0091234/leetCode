
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}
void quickSort(vector<int> &array,int left,int right)  //使用快速排序
{
    if(left<right)
    {
        int i=left,j =right;
        int tmp =array[left];
        while(i<j)
        {
            while(i<j && array[j]>=tmp)
            j--;
            while(i<j&&array[i]<=tmp)
            i++;
            if(i<j)
            {
                int tmp =array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
        array[left]=array[i];
        array[i]=tmp;
        // cout<<"i:"<<i<<endl;
        quickSort(array,left,i-1);
        quickSort(array,i+1,right);
        
    }
}


int  quickSort1(vector<int> &array,int left,int right,int k)
{
    if(left<right)
    {
        int i=left,j =right;
        int tmp =array[left];
        while(i<j)
        {
            while(i<j && array[j]>=tmp)
            j--;
            while(i<j&&array[i]<=tmp)
            i++;
            if(i<j)
            {
                int tmp =array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
        array[left]=array[i];
        array[i]=tmp;
        if(i<=k && left==0)
        return 0;
        quickSort1(array,left,i-1, k);
        quickSort1(array,i+1,right,k);
        
    }
    else
    return 1;
}
  

  
  vector<int> getLeastNumbers(vector<int>& arr, int k) {       //方法1，先用快排，然后找出前面的k个数就行了
         
         quickSort(arr,0,arr.size()-1);
         show(arr);
         return vector<int> (arr.begin(),arr.begin()+k);
    }

  vector<int> getLeastNumbers1(vector<int>& arr, int k) {       //方法1，先用快排，然后找出前面的k个数就行了
         
         quickSort1(arr,0,arr.size()-1,k);
         show(arr);
         return vector<int> (arr.begin(),arr.begin()+k);
    }


//方法2 构建最大堆
void heapfy(vector<int> &nums,int len,int parent) //将parent变为最大的
{
 int leftChild = 2*parent+1;
 while(leftChild<len)
 {
     if(leftChild+1<len && nums[leftChild]<nums[leftChild+1])
     {
         leftChild++;
     }
     if(nums[parent]>nums[leftChild])
     return ;
     swap(nums[parent],nums[leftChild]);
     parent =leftChild;
     leftChild=2*leftChild+1;
 }
}
void buildHeap(vector<int>&nums,int len)
{
    for(int i = (len-2)/2;i>=0; i--)
    heapfy(nums,len,i);
}

void heapSort(vector<int> &nums)                     //堆排序
{
    buildHeap(nums,nums.size());
    for(int i = nums.size()-1; i>0; i--)
    {
        swap(nums[0],nums[i]);
         cout<<"before heapfy:";
         show(nums);
        heapfy(nums,i,0);
         cout<<"after heapfy:";
         show(nums);
    }
}

vector<int> minNumOfK(vector<int> &nums,int k )  //最小k个数采用堆来实现
{
    if(k<1)
    return vector<int>{};
    buildHeap(nums,k);                 //首先构建一个长度为k的大顶堆，然后让后面的数和堆顶比较，如果比堆顶大，说明不符合条件，如果比堆顶小，那么将堆顶元素删除，将这个小的数，放在堆顶，然后heapfy一下，堆顶就变为下一个最大的数
    for(int i = k; i<nums.size(); i++)
    {
        if(nums[i]<nums[0])
        {
            nums[0] = nums[i];
            heapfy(nums,k,0);
        }
    }
    return vector<int>(nums.begin(),nums.begin()+k);
}

    
int main(int argc, char **argv)
{
    vector<int> array{0,0,0,2,0,5};
    vector<int> MerGearray1{4,2,5,1,9,8,5,2,7,1,4,9,3,6,0};
     vector<int> arr{9,6,5,2,1,4,7,8};
    // quickSort(MerGearray1,0,MerGearray1.size()-1);
    // show(MerGearray1);
    // show(MerGearray1);
    // show(getLeastNumbers(array,0));
    show(minNumOfK(MerGearray1,4));
    // heapSort(arr);
    // show(arr);
    return 0;
}

