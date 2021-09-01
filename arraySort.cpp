#include <iostream>
#include <vector>
using namespace std;
void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}

void  quickSort(vector<int> & p,int i,int j ) //快排
{
    
    if(i<j)
    {
    int temp =p[i];
    int left =i,right =j;
    while(left<right)
    {
        while(p[right]>=temp &&left<right)  //从右找小于temp 基准的数字
        right--;
        if(left<right)
        {
           p[left++]=p[right];
        }
        while(p[left]<=temp&&left<right)
        left++;
        if(left<right)
        {
            p[right--]=p[left];
        }
    }
    p[left]=temp;
    quickSort(p,i,left-1);
    quickSort(p,left+1,j);
    }
    
}

void insertSort3(vector<int>&array) //插入排序
{
    for(int i = 1; i<array.size(); i++)
    {
        int  tmp = array[i];
        int j;
        for(j = i-1;j>=0 &&array[j]>tmp;j--)
        {
              array[j+1]=array[j];
        }
         array[j+1]=tmp;
    }
}

void MergeArray(vector<int>&array,int left,int mid ,int right)
{
    vector<int > tmp(right-left+1,0);
    // tmp.reserve(array.size());
    int i = left,j = mid+1;               //i是left不是0,记住
    int k = 0;
    while(i<=mid&&j<=right)
    {
        if(array[i]<array[j] )
        tmp[k++]=array[i++];
        else 
        tmp[k++]=array[j++];
    }
    while(i<=mid)            //这里用while 不是用
    tmp[k++]=array[i++];
    while(j<=right)            //用while 不是if
    tmp[k++]=array[j++];

    i = left,j = 0;        //i从left开始
    while(j<k)
    array[i++]=tmp[j++];  
}

void MergeSort(vector<int>&array,int left,int right)
{
    
    if(left<right)
    {
         int mid = (left+right)/2;
         
         MergeSort(array,left,mid);
         MergeSort(array,mid+1,right);
        MergeArray(array,left,mid,right);
    }
}

void hillSort(vector<int>&array)
{
    for(int gap=array.size();gap>0; gap/=2)
    {
        for(int i = gap; i<array.size();i++)
        {
            int tmp = array[i];
            int pos = i-gap;
            while(pos>=0 && array[pos]>tmp)
        }
    }
}



int main(int argc, char **argv)
{
    vector<int> array{9,8,7,6,5,4,3,2,10};
    vector<int> MerGearray1{4,2,5,1};
    show(MerGearray1);
    // quickSort(array,0,array.size()-1);
    insertSort3(array);
    // MergeSort(array,0,array.size()-1);
     show(array);
    return 0;
}