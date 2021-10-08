#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
template<typename T>
void show(vector<T> &nums)
{
        for(auto &s:nums)
        cout<<s<<" ";
        cout<<endl;
}
struct TreeNode
{
    TreeNode(int val):val(val),left(NULL),right(NULL),next(NULL){}
    int val;
    TreeNode *left,*right,*next;
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

     vector<double> averageOfLevels(TreeNode* root)   //二叉树的层平均值
     {  
       queue<TreeNode*> myQueue;
       vector<double> output;
       if(root)
       myQueue.push(root);
       while(!myQueue.empty())
       {
           int size = myQueue.size();
           double sum = 0;
           vector<int> result;
           for(int i = 0; i<size; i++)
           {
               TreeNode *tmp = myQueue.front();
               myQueue.pop();
               sum+=tmp->val;
               if(tmp->left)
               myQueue.push(tmp->left);
               if(tmp->right)
               myQueue.push(tmp->right);
           }
          output.push_back(sum/size);    
       }
       return output;
    }


     vector<int> largestValues(TreeNode* root) 
     {
        vector<int> result;
        queue<TreeNode *> myQueue;
        if(root) myQueue.push(root);
        
        while(!myQueue.empty())
        {
           
            int size = myQueue.size();
            int max = myQueue.front()->val;
            for(int i = 0; i<size; i++)
            {
                TreeNode *tmp =myQueue.front(); 
                int val = tmp->val;
                if(val>max)
                  max =val;
                 myQueue.pop();
                 if(tmp ->left)
                 myQueue.push(tmp->left);
                 if(tmp->right)
                 myQueue.push(tmp->right);
            }
            result.push_back(max);
        }
           return result;
    }

//  vector<vector<int>> levelOrder(TreeNode* root) //层序遍历
//     {
//        queue<TreeNode*> myQueue;
//        vector<vector<int>> output;
//        if(root)
//        myQueue.push(root);
//        while(!myQueue.empty())
//        {
//            int size = myQueue.size();
//            vector<int> result;
//            for(int i = 0; i<size; i++)
//            {
//                TreeNode *tmp = myQueue.front();
//                myQueue.pop();
//                result.push_back(tmp->val);
//                if(tmp->left)
//                myQueue.push(tmp->left);
//                if(tmp->right)
//                myQueue.push(tmp->right);
//            }
//           output.push_back(result);    
//        }
//     //    reverse(output.begin(),output.end());
//        return output;
        
//     }
typedef TreeNode Node ;
    Node* connect(Node* root) 
    {
        queue<Node *> myQueue;
        if(root)
        myQueue.push(root);
        while(!myQueue.empty())
        {
            Node *tail=NULL;
            Node *tmp =NULL;
            int size = myQueue.size();
            for(int i = 0; i<size; i++)
            {
                if(i == 0)
                {
                   tmp = myQueue.front();
                   tail =tmp;
                }
                else
                {
                    tmp = myQueue.front();
                    tail->next =tmp;
                    tail=tmp;

                }
                myQueue.pop();
                if(tmp->left)
                myQueue.push(tmp->left);
                if(tmp->right)
                myQueue.push(tmp->right);
                
            }
            tail->next =NULL;
        }
        return root;
    }
int main(int argc, char **argv)
{
    vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    show(array);
    int index = 0;
    auto root = initTree(array,index);
 
    auto  result = levelOrder(root);
    // reverse(array.begin(),array.end());
    for(int i = 0; i<result.size(); i++)
    show(result[i]);


   
    
    return 0;
}