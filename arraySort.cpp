#include <iostream>
#include <vector>
using namespace std;
void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}

int  quickSort(vector<int> & p,int i,int j )
{
    if(i>=j)                     //递归出口
    return  0;
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
void insertSort(vector<int> &array)  //插入排序
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

int main(int argc, char **argv)
{
    vector<int> array{1,3,2,5,7,5,4};
    show(array);
    // quickSort(array,0,4);
    insertSort(array);
     show(array);
    return 0;
}