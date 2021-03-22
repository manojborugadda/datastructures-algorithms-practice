#include <iostream>
#include<stack>
using namespace std;
                                  /// Time complexity - O(n)
struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char  data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(TreeNode *root,int &d)    /// we take the maximum of (heights of right subtree and left subtree
{
    if(root == NULL)
    {
        return -1;
    }
    int Leftree = height(root->left,d);
    int Rightree = height(root->right,d);
    d = max(d, Leftree + Rightree + 2);
    return max(Leftree , Rightree) + 1;
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('G');
    root->right->right->left = new TreeNode('B');
    root->right->right->left->right = new TreeNode('E');

    cout<<"Diameter of Binary Tree \n";
    int d;
    d = 0;
    height(root,d);
    cout<<d;

    return 0;
}


