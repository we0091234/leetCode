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
vector<int> inorderTraversal(BinaryTree *root) //二叉树的中序遍历
{
    vector<int> result;
    stack<BinaryTree *> myStack;
    BinaryTree *Node = root->left;
    myStack.push(root);
    while(Node || !myStack.empty())
    {
        if(Node)
        {
            myStack.push(Node);
            Node =Node ->left;
        }
        else
        {
           Node = myStack.top();myStack.pop();
           result.push_back(Node->val);
           Node = Node ->right;
           
        }
    }
    return result;
}



int main(int argc, char **argv)
{
    vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    // show(array);
    int index = 0;
    auto root = initTree(array,index);
    iterativeTraversal(root);
      cout<<endl;
    auto result =inorderTraversal(root);
    show(result);
  

    // auto newRoot = reverseBinaryTree(root);
    // iterativeTraversal(newRoot);
    // cout<<endl;
    
    return 0;
}