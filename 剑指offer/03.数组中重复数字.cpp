
#include <iostream>
#include <vector>
#include <map>
using namespace std;


 int findRepeatNumber(vector<int>& nums) {
     map<int ,int >mymap;


     for(int  i = 0; i<nums.size();i++)
     {
         if(mymap.find(nums[i]) != mymap.end())
         {
             return nums[i];
         }
         mymap[nums[i]] =i;
     }
     return 0;

    }


int main(int argc, char **argv)
{
    vector<int> array{1,2,3,4,4};
    vector<int> MerGearray1{4,2,5,1};
    
    cout<<findRepeatNumber(array)<<endl;
    return 0;
}

