#include <vector>
#include <iostream>
#include <string>

using namespace std;
vector<string> path;

bool isIP(vector<string>&mystrVec)
{
    for(auto &s :mystrVec)
    {
        int number = atoi(s.c_str());
        if(number<0 || number>255)
        return false;
    }
    return true;
}
void backTrace(string &mystr,int index,vector<vector<string>> &result)
{
    if(index>=mystr.size())
    {
        // if(isHuiwenVec(path))
        if(path.size()==4&& isIP(path))
        result.push_back(path);
    return ;
    }
    for(int i = index; i<mystr.size(); i++)
    {
        int len = i-index+1;
        if(len>3)
        continue;
        path.push_back(mystr.substr( index,i-index+1));
        backTrace(mystr,i+1,result);
        path.pop_back();
    }
    
}
vector<string> restoreIpAddresses(string s)
{
    vector<vector<string>> result;
    vector<string> result1;
     backTrace(s,0,result);
    for(auto &st:result)
    {
    string mystr="";
    for (auto &c:st)
       mystr+=c+'.';
    mystr.pop_back();
     result1.push_back(mystr);
    }
   
   return result1;
     
}

int main(int argc, char** argv)
{

   
    auto result=restoreIpAddresses("0000");
    for(auto &s:result)
    {
   
    cout<<s<<endl;
    }
    return 0;
}