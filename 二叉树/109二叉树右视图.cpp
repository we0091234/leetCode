#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void show(vector<int> &nums)
{
        for(auto &s:nums)
        cout<<s<<" ";
        cout<<endl;
}
struct TreeNode
{
    TreeNode(int val):val(val),left(NULL),right(NULL){}
    int val;
    TreeNode *left,*right;
};
TreeNode * initTree(vector<int> &array,int &index)  //index一定要用引用
{
    TreeNode *root =NULL;
    if(index<array.size()&& array[index]!='#')
    {
        root = new TreeNode(array[index]);
        root->left=initTree(array,++index);
        root->right=initTree(array,++index);
    }
    return root;
}

void traverse(TreeNode *root)  //遍历
{
    if(!root) return;
   cout<<root->val<<" ";   //前序遍历
   traverse(root->left);
    //  cout<<root->val<<" ";   //中序遍历
   traverse(root->right);
    //   cout<<root->val<<" ";   //后序遍历
    // cout<<endl;
}

    vector<vector<int>> levelOrder(TreeNode* root) //层序遍历
    {
       queue<TreeNode*> myQueue;
       vector<vector<int>> output;
       if(root)
       myQueue.push(root);
       while(!myQueue.empty())
       {
           int size = myQueue.size();
           vector<int> result;
           for(int i = 0; i<size; i++)
           {
               TreeNode *tmp = myQueue.front();
               myQueue.pop();
               result.push_back(tmp->val);
               if(tmp->left)
               myQueue.push(tmp->left);
               if(tmp->right)
               myQueue.push(tmp->right);
           }
          output.push_back(result);    
       }
    //    reverse(output.begin(),output.end());
       return output;
        
    }

     vector<int> rightSideView(TreeNode* root)   //二叉树的右视图
     {  
       queue<TreeNode*> myQueue;
       vector<int> output;
       if(root)
       myQueue.push(root);
       while(!myQueue.empty())
       {
           int size = myQueue.size();
           int sum = 0;
           vector<int> result;
           for(int i = 0; i<size; i++)
           {
               TreeNode *tmp = myQueue.front();
               myQueue.pop();
               result.push_back(tmp->val);
               if(tmp->left)
               myQueue.push(tmp->left);
               if(tmp->right)
               myQueue.push(tmp->right);
           }
          output.push_back(result[result.size()-1]);    
       }
    //    reverse(output.begin(),output.end());
       return output;
    }


int main(int argc, char **argv)
{
    vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    show(array);
    int index = 0;
    auto root = initTree(array,index);
 
    auto  result = rightSideView(root);
    // reverse(array.begin(),array.end());
    show(result);


   
    
    return 0;
}