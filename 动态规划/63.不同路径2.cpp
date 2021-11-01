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
 
 
   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       vector<vector<int>> nums(obstacleGrid.size(),vector<int>(obstacleGrid[0].size()));
       nums[0][0]=1;
       int index=0,index1=0;
       for(int i = 0; i<m; i++)
       {
           for(int j = 0; j<n; j++)
           {
               if(obstacleGrid[i][j]==1)
               
               {
                   index=i;
                   index1=j;
                   nums[i][j]=0;
               }
           }
       }

         for(int i = 1; i<m; i++)
       {
           if(obstacleGrid[i][0]!=1)
           nums[i][0]=nums[i-1][0];
       }

         for(int i = 1; i<n; i++)
       {
           if(obstacleGrid[0][i]!=1)
           nums[0][i]=nums[0][i-1];
       }

         for(int i=1;i<m;i++)
     {
         for(int j =1; j<n; j++)
         {
              if(obstacleGrid[i][j]==1)
              nums[i][j]=0;
              else 
               nums[i][j]=nums[i-1][j]+nums[i][j-1];      
         }
     }
     return nums[m-1][n-1];

    }


int main(int argc, char **argv)
{
//   cout<<uniquePathsWithObstacles()<<endl;
// vector<vector<int >> nums{{1,0}};
// vector<vector<int >> nums{{0,0,0},{0,1,0},{0,0,0}};
vector<vector<int >> nums{{0,1},{0,0}};
cout<<uniquePathsWithObstacles(nums)<<endl;
    return 0;
}