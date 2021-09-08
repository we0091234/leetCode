
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void show(vector<int> p,int len)
{
    for(int i = 0; i<len; i++)
    cout<<p[i]<<" ";
    cout<<endl;
}
 void myquickSort(vector<int>&nums,int l,int r)
 {
     if (l<r){
         int i = l,j = r;
         int tmp =nums[i];
         while(i<j)
         {
            while(i<j &&nums[j]>=tmp)  //用while
            j--;
            while(i<j &&nums[i]<=tmp)
            i++;
            if(i<j)
            swap(nums[i],nums[j]);
         }
         nums[l]=nums[i];
         nums[i]=tmp;
         myquickSort(nums,l,i-1);
         myquickSort(nums,i+1,r);
     }
 }
 int removeDuplicates(vector<int>& nums) {  //使用map
      set<int>myset;
      int k = 0;
      for(int i = 0; i<nums.size();i++)
      {
          if(myset.find(nums[i])==myset.end())
          {
          myset.insert(nums[i]);
          nums[k++]=nums[i];
          }
      }
      return myset.size();
      

    }

     int removeDuplicates1(vector<int>& nums) {
    //   set<int>myset;
     
      int size = nums.size();
      for(int i = 0; i<size;i++)
      {
          int len ;
          int j = i+1;
         while(nums[i]==nums[j]) j++;
         len = j-i-1;                   //超出的长度，比如 222，留下一个2，超出了3-1=2个
         if(len>=1)
         {
             for(int k = i+1;k<size-len;k++)
               nums[k]=nums[k+len];

               size-=len;
         }
        
      }
      
      
        //    return size;
    }
    
int main(int argc, char **argv)
{
    vector<int> array{0,0,0,2,0,5};
    vector<int> MerGearray1{4,2,5,1,9,8,5,2,7,1,4,9,3,6,0};
     vector<int> arr{1,1,2};
    // quickSort(MerGearray1,0,MerGearray1.size()-1);
    // show(MerGearray1);
    // show(MerGearray1);
    // show(getLeastNumbers(array,0));
    // show(minNumOfK(MerGearray1,4));
    // myquickSort(array);
    myquickSort(arr,0,arr.size()-1);

    int len = removeDuplicates1(arr);
    show(arr,len);
    return 0;
}

