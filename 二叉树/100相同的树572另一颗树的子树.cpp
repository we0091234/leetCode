#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
#include<stack>
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
bool isHuiwen(vector<int >nums)
{
    int i = 0,j = nums.size()-1;
    while(i<=j)
    {  
        if(nums[i]!=nums[j])
        return false;
        i++;j--;
    }

    return true;
}

bool isSymmetric(TreeNode* root)   //迭代法
{ 
    queue<TreeNode *> myQueue;
    if(root)
    {
    myQueue.push(root->left);
    myQueue.push(root->right);
    }
    
        while(!myQueue.empty())
        {
            TreeNode *left = myQueue.front(); myQueue.pop();
            TreeNode *right = myQueue.front();myQueue.pop();
            if(!left&&!right)
            continue;
            if(!left||!right||(left->val!=right->val))
            return false;
            myQueue.push(left->left);
            myQueue.push(right->right);
            myQueue.push(left->right);
            myQueue.push(right->left);
            
        }


        return true;

}
bool compare(TreeNode *left,TreeNode *right)
{
    if(!left&&right) return false;
    else if(left&&!right) return false;
    else if(!left&&!right) return true;
    else if(left->val != right->val) return false;
    
    bool cmp1 = compare(left->left,right->right);
    bool cmp2 = compare(left->right,right->left);
    return cmp1&&cmp2;

}
bool recursiveSymmetry(TreeNode* root)
{
    if(!root)  return true;
    return compare(root->left,root->right);
}

   bool isSameTree(TreeNode* p, TreeNode* q)  //相同的树
    {  
        if(!p&&q) return false;
        else if(p&&!q) return false;
        else if(!p&&!q) return true;
        else if(p->val!=q->val) return false;
        
        bool cmp1 = isSameTree(p->left,q->left);
        bool cmp2 = isSameTree(p->right,q->right);
        return cmp1&&cmp2;
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //子树判断

        stack<TreeNode *>myStack;
        if(root)
        myStack.push(root);
        while(!myStack.empty())
        {
            TreeNode *tmp = myStack.top();
            myStack.pop();
            if(isSameTree(tmp,subRoot))
            return true;
            if(tmp->right)
            myStack.push(tmp->right);
              if(tmp->left)
            myStack.push(tmp->left);
            
        }
        return false;
    }

int main(int argc, char **argv)
{
    // vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    vector<int> array {1,2,3,'#','#',4,'#','#',2,4,'#','#',3};
    vector<int> array1 {1,2,3,'#','#',4,'#','#',2,4,'#','#',1};
    // vector<int> array {1,2,1};
    show(array);
    int index1 = 0;
    int index2 = 0;
    auto root = initTree(array,index1);
       auto root1 = initTree(array1,index2);
    auto output=levelOrder(root);
    for(auto &s:output)
    {
        show(s);
    }

    // reverse(array.begin(),array.end());
    // show(array);
    cout<<isSameTree(root,root1)<<endl;

    // cout<<isHuiwen(array)<<endl;


   
    
    return 0;
}