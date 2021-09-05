  #include <iostream>
  #include <string>
  #include <vector>
  using namespace std;
  
  string replaceSpace(string s) {  //借助一个tmp实现，额外开辟了空间 
      string tmp ="";
      for(auto &c:s)
      {
          if(c!=' ')
          tmp+=c;
          else 
          tmp+="%20";
      }
      return tmp;
    }

//   string replaceSpace(string s) {  //不开辟空间试试
//       for(int i = 0; i < s.length(); i++)
//       {

//       }
//     }


int main(int argc,char **argv)
{
    string s = "We are happy";
    // for(int i = s.size()-1;i>=0; i--)
    // {
    //     s[i+1]=s[i];
    // }
    // s = replaceSpace(s);
    cout<<s[s.size()]<<endl;
}