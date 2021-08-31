#include <iostream>
#include <vector>
using namespace std;
void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}

void  quickSort(vector<int> & p,int i,int j )
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
void insertSort(vector<int> &array)  //插入排序我的实现1
{
    int i = 1;
    int index= 1;  //当前待插入的数组长度
    while(i<array.size())
    {
        int j = 0;
        while(array[i]>array[j] && j<index)
        j++;
        int temp = array[i];
        for(int k =index; k>j;k--)
           array[k]=array[k-1];
           array[j]=temp;
          index +=1;
         i++;
    }
}

void insertSort2(vector<int> &array)  //插入排序 参考他人实现
{
   int pos ,tmp;
   for(int i = 1; i<array.size(); i++)
   {
       tmp = array[i];
       pos=i-1;
       while(pos>=0 && array[pos]>tmp)
       {
           array[pos+1]=array[pos];
           pos--;
       }
       array[pos+1]=tmp;
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


void MergeArray(vector<int>&array)
{
    
}


int main(int argc, char **argv)
{
    vector<int> array{9,8,7,6,5,4,3,2,10};
    show(array);
    quickSort(array,0,array.size()-1);
    // insertSort3(array);
     show(array);
    return 0;
}