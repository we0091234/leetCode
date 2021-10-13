#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
string path;
map<char ,string> myMap;

vector<string> myStrVec;

void transition(string digits,int index,vector<string> &result)
{
      if(path.size()==digits.size())
      {
        result.push_back(path);
          return;
      }
      for(int i =0; i<myStrVec[index].size(); i++)
      {
          path.push_back(myStrVec[index][i]);
          transition(digits,index+1,result);
          path.pop_back();
      }
}
vector<string> letterCombinations(string digits)
  {
     
    vector<string > result;
     if (digits=="") return result;
     string letter = "abcdefghijklmnopqrstuvwxyz";
     int i = 0;
      for(char chr='2';chr<='9';chr++)
    {
        
        if(chr =='7' || chr =='9')
        {
              myMap[chr]=letter.substr(i,4);
              i+=4;
        }
        else{
        
             myMap[chr]=letter.substr(i,3);
        i+=3;
        }
    
    }


       for(int i = 0; i<digits.size(); i++)
       {
            myStrVec.push_back(myMap[digits[i]]);
       }

       transition(digits,0,result);
       return result;
   
}

int main(int argc, char **argv)
{
 
   

   auto result =letterCombinations("45");
   for(auto &s:result)
   cout<<s<<endl;

    return 0;
}