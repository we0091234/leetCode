
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
void quickSort(vector<int> &array,int left,int right)
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

    
int main(int argc, char **argv)
{
    vector<int> array{9,6,3,8,7,4,1};
    vector<int> MerGearray1{4,2,5,1,9,8,5,2,7,1,4,9,3,6,0};
    // quickSort(MerGearray1,0,MerGearray1.size()-1);
    // show(MerGearray1);
    // show(MerGearray1);
    show(getLeastNumbers1(array,4));
    return 0;
}

