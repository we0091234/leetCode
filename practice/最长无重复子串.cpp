#include <string>
#include <iostream>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
    map<char,int> myMap;
    int maxLen=  0;
    int j =0;
    for(int i=  0; i<s.length(); i++)
    {
      if(myMap.find(s[i])!=myMap.end())
      {
          j= max(myMap[s[i]],j);
      }

       myMap[s[i]]=i+1;
       maxLen=max(maxLen,i-j+1); 
    }
    
    return maxLen;

}

int main(int argc, char **argv) {
    string s = "abcba";
    cout<<lengthOfLongestSubstring(s)<<endl;
}