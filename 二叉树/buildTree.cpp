#include <iostream>
#include <vector>
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

void traverse(BinaryTree *root)
{
    if(!root) return;
  //  cout<<root->val<<" ";   //前序遍历
   traverse(root->left);
     cout<<root->val<<" ";   //中序遍历
   traverse(root->right);
    //   cout<<root->val<<" ";   //后序遍历

}

int main(int argc, char **argv)
{
    vector<int> array {1,2,3,'#','#',4,'#','#',5,6};
    show(array);
    int index = 0;
    auto root = initTree(array,index);
    traverse(root);
    
    return 0;
}