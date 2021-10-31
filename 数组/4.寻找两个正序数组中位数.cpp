#include<iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int *nums3 = new int[nums1.size()+nums2.size()];
    int i = 0,j=0;
    int k = 0;
    while(i<nums1.size() && j<nums2.size())  //两个数组小的先存进nums3
    {
        if(nums1[i]<nums2[j])
         nums3[k++]=nums1[i++];
         else
         nums3[k++]=nums2[j++];
    }
    while(i<nums1.size())
    nums3[k++]=nums1[i++];
    while(j<nums2.size())
    nums3[k++]=nums2[j++];
   
    // for(int i = 0; i<k;i++)
    // cout<<nums3[i]<<" ";
    if (k%2)
    return nums3[k/2];
    else
    return  1.0*(nums3[k/2-1]+nums3[k/2])/2;  
    // return 1;
}

int main()
{
    vector<int >nums1{1,2};
    vector<int >nums2{3,4};

    double result = findMedianSortedArrays(nums1,nums2);
    cout<<result<<endl;
}