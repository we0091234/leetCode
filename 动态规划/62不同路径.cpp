 #include <iostream>
 #include <vector>
 using namespace std;
 void show(vector<int> nums)
 {
     for (auto &s:nums)
     {
         cout<<s<<" ";
     }
     cout<<endl;
 }
 
 
  int uniquePaths(int m, int n) {
      vector<vector<int>> nums(m,vector<int>(n));
        // return 1;
     for(int i = 0; i<n; i++)
     {
         nums[0][i]=1;
     }
      for(int i = 0; i<m; i++)
     {
         nums[i][0]=1;
     }
     for(int i=1;i<m;i++)
     {
         for(int j =1; j<n; j++)
         {
             nums[i][j]=nums[i-1][j]+nums[i][j-1];
         }
     }
     return nums[m-1][n-1];
    }


int main(int argc, char **argv)
{
  cout<<uniquePaths(3,3)<<endl;
    return 0;
}