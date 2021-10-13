#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<char> path;
void letterCombinations(string digits, vector<pair<char,string>> myPair,int index)
  {
      if(path.size()==digits.size())
      {
          for(auto &s:path)
          cout<<s;
          cout<<endl;
          return;
      }
      for(int i =0; i<myPair[index].second.size(); i++)
      {
          path.push_back(myPair[index].second[i]);
          letterCombinations(digits,myPair,index+1);
          path.pop_back();
      }
      
   
}

int main(int argc, char **argv)
{
    vector<pair<char,string>> myPair;
    map<char ,string> myMap;
    string letter = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    pair<char,string> pairSon;
    for(char chr='2';chr<='9';chr++)
    {
        // myMap[chr]=letter.substr(i,3);
        if(chr =='7' || chr =='9')
        {
              pairSon = make_pair(chr,letter.substr(i,4));
              i+=4;
        }
        else{
         pairSon = make_pair(chr,letter.substr(i,3));
        i+=3;
        }
        myPair.push_back(pairSon);
    }
//    letterCombinations("",myPair,0);
    for(auto  &s:myPair)
    cout<<s.first<<" "<<s.second<<endl;
    return 0;
}