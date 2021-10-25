#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; //



vector<string> strSplit(string &s)
{
    string oriSub = s;
    vector<string> result;
    int loc;
    while((loc=oriSub.find(" "))!=string::npos)
    {
    string mysub = oriSub.substr(0,loc);
     oriSub = oriSub.substr(loc+1);
     if (mysub.size()<1)
     continue;
     result.push_back(mysub);
    }
     if (oriSub.size()>=1)
  result.push_back(oriSub);
  reverse(result.begin(),result.end());
  return result;
}

 string reverseWords(string s) {

    string newResult = "";
    auto result =  strSplit(s);

    for (int i = 0; i<result.size(); i++) 
    {
        if(i==result.size()-1)
        newResult +=result[i];
        else
        newResult +=result[i]+" ";
    }
    
        return newResult;
    }

int main(int argc, char **argv)
{
    string str = " hello world ";
    auto result=reverseWords(str);
    cout<<result<<endl;
    
    return 0;
}