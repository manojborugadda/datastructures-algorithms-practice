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

TreeNode *zigzag_levelorder_traversal_twostacks(TreeNode *root)   /// Zig Zag (or) Spiral order traversal of the binary tree-------
{
    stack<TreeNode *>s1,s2;
    s1.push(root);
    while(!s1.empty()|| !s2.empty())
    {
        while(!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            cout<<temp->val<<" ";
            if(temp->right !=NULL)
            {
                s2.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s2.push(temp->left);
            }
        }
        while(!s2.empty())  ///checking if stack2 is empty
        {
           TreeNode *temp = s2.top();
           s2.pop();
           cout<<temp->val<<" ";
           if(temp->left!=NULL)
           {
               s1.push(temp->left);
           }
           if(temp->right!=NULL)
           {
               s1.push(temp->right);
           }

        }
    }
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('C');
    root->right->left->left = new TreeNode('B');
    root->right->left->right = new TreeNode('G');

    cout<<"zigzag level order traversal of Binary Tree \n";
    zigzag_levelorder_traversal_twostacks(root);
    cout<<endl;

    return 0;
}


