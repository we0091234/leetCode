#include <iostream>
#include <vector>
using namespace std;
void show(vector<int> p)
{
    for(auto &s:p)
    cout<<s<<" ";
    cout<<endl;
}



void rotate(vector<int>&array,int k)  //自己实现
{
    k = k%array.size();
   int *temp = new int[k];        //1将待旋转的数放入一个新数组
   int j = array.size()-k;         //找到待旋转的第一个数的下标  比如1,2,3,4,5  k=2，那么4的坐标为5-2=3
   int i = 0;
   while(j<array.size())
   {
       temp[i++]=array[j++];
   }

   for(int i = array.size()-1; i>=k ; i--)  //前面的数字往后面移动k
   {
       array[i] = array[i-k];
   }
   for(int i = 0; i<k; i++)  //最后将新数组的数移动到原数组前段
   {
       array[i]=temp[i];
   }
}
void rotate1(vector<int>&array,int k)  //自己实现
{
    k = k%array.size();
    int j =array.size()-k;    //找到待旋转的第一个数下标
    int begin = 0;
    int last = j-1;
    while(j<array.size())
    {
        int tmp = array[j];
    for(int i =j-1;i>=begin;i--)
    {
        array[i+1]=array[i];
    }
    array[begin]=tmp;
    j++;
    begin++;
    }
   
}

void reverse(vector<int>&array,int l,int r)  //[l,r]内进行反转
{
    while(l<r)
    {
        int tmp = array[l];
        array[l]=array[r];
        array[r]=tmp;
        l++;
        r--;
    }
}
void rotate2(vector<int>&nums,int k)  //官方实现1 例如输入【1,2,3,4,5】 k=2
{
    int len = nums.size();
    k = k%len;
    reverse(nums,0,len-1);             //[1,2,3,4,5] -> [5,4,3,2,1]
    reverse(nums,0,k-1);               //[5,4,3,2,1]->[4,5,3,2,1]
    reverse(nums,k,len-1);             //[4,5,3,2,1]->[4,5,1,2,3]  完成

}

int main(int argc, char **argv)
{
    vector<int> array{-1};
    vector<int> MerGearray1{4,2,5,1};
    show(MerGearray1);
    // quickSort(array,0,array.size()-1);
    // insertSort3(array);
    rotate2(MerGearray1,4);
     show(MerGearray1);
    return 0;
}