#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;
vector<string> splitString(string &mystr,string split)  //字符串分割
{
    vector<string > result;
    string newstr = mystr;
    int loc;
    while(true)
    {
    loc = newstr.find(split);
    if(loc == string::npos)
    {
        result.push_back(newstr);
        break;
    }
    string subStr = newstr.substr(0,loc);
    newstr = newstr.substr(loc+1);
    result.push_back(subStr);
    }

    return result;
}

string reverseString(string &mystr)
{
    int i = 0,j = mystr.size()-1;
    while(i<=j)
    {
        auto tmp = mystr[i];
        mystr[i]=mystr[j];
        mystr[j]=tmp;
        i++;j--;
    }
    return mystr;
}


int main(int argc, char **argv)
{
//    char  mystr1[100] ;
//    cin.getline(mystr1,100); 
//    auto mystr = string(mystr1);
//     // cout<<reverseString(mystr)<<endl;
//    auto result = splitString(mystr," ");
   
//    cout<<result[result.size()-1].size()<<endl;
vector<int> nums{9,9,8,7,9,4,3,3,2,1,2};
set<int> myset;
for(int i = 0; i<nums.size(); i++)
myset.insert(nums[i]);

for(auto iter = myset.begin(); iter!=myset.end();iter++)
cout<<*iter<<endl;

}