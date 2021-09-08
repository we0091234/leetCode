
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
void buildHeap(vector<int>&nums)
{
    for(int i = (nums.size()-2)/2;i>=0; i--)
    heapfy(nums,nums.size(),i);
}

void heapSort(vector<int> &nums)
{
    buildHeap(nums);
    for(int i = nums.size()-1; i>0; i--)
    {
        swap(nums[0],nums[i]);
        heapfy(nums,i,0);
    }
}

    
int main(int argc, char **argv)
{
    vector<int> array{9,6,3,8,7,4,1};
    vector<int> MerGearray1{4,2,5,1,9,8,5,2,7,1,4,9,3,6,0};
    // quickSort(MerGearray1,0,MerGearray1.size()-1);
    // show(MerGearray1);
    // show(MerGearray1);
    // show(getLeastNumbers1(array,4));
    heapSort(MerGearray1);
    show(MerGearray1);
    return 0;
}

