#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void show(vector<int> &nums)
{
        for(auto &s:nums)
        cout<<s<<" ";
        cout<<endl;
}
struct BinaryTree
{
    BinaryTree(int val):val(val),left(NULL),right(NULL){}
    int val;
    BinaryTree *left,*right;
};
BinaryTree * initTree(vector<int> &array,int &index)  //index一定要用引用
{
    BinaryTree *root =NULL;
    if(index<array.size()&& array[index]!='#')
    {
        root = new BinaryTree(array[index]);
        root->left=initTree(array,++index);
        root->right=initTree(array,++index);
    }
    return root;
}

void traverse(BinaryTree *root)  //遍历
{
    if(!root) return;
   cout<<root->val<<" ";   //前序遍历
   traverse(root->left);
    //  cout<<root->val<<" ";   //中序遍历
   traverse(root->right);
    //   cout<<root->val<<" ";   //后序遍历
    // cout<<endl;
}
void iterativeTraversal(BinaryTree *root)  //先序迭代遍历
{
  stack<BinaryTree *> myStack;
  if(root)
  myStack.push(root);
  while(!myStack.empty())
  {
    auto tmp =myStack.top();
    cout<<tmp->val<<" ";
    myStack.pop();
    if(tmp->right)
    myStack.push(tmp->right);
    if(tmp->left)
    myStack.push(tmp->left);

  }
}

vector<int>    iterativeSubsequentTraversal(BinaryTree *root) //迭代后续遍历，在先序遍历上面改，中左右 -》 中右左 -》 左右中
{
     stack<BinaryTree *> myStack;
     vector<int> result;
  if(root)
  myStack.push(root);
  while(!myStack.empty())
  {
    auto tmp =myStack.top();
    result.push_back(tmp->val);
    myStack.pop();
  
    if(tmp->left)                //先左后右
    myStack.push(tmp->left);
    if(tmp->right)
    myStack.push(tmp->right);
  }
  reverse(result.begin(),result.end());
  show(result);
  return result;
}


 BinaryTree *reverseBinaryTree(BinaryTree *root) //翻转二叉树
{
    if(!root) return NULL;
    

      reverseBinaryTree(root->right);
        reverseBinaryTree(root->left);
        auto tmp = root->right;
        root->right = root->left;
        root->left=tmp;
      
        
    return root;
    
    
}

int main(int argc, char **argv)
{
    vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    // show(array);
    int index = 0;
    auto root = initTree(array,index);
    iterativeSubsequentTraversal(root);
    cout<<endl;

    // auto newRoot = reverseBinaryTree(root);
    // iterativeTraversal(newRoot);
    // cout<<endl;
    
    return 0;
}