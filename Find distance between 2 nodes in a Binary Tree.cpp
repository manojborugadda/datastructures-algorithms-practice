#include <iostream>
#include<stack>
using namespace std;
                                  /// Time complexity - O(n)
struct TreeNode
{
    char val; 
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* lca(TreeNode *node, int  n1, int n2)     /// finding LCA for the given nodes-----------
{
    if (node == NULL)
       return NULL;
    if (node->val == n1 || node->val == n2)
       return node;

    TreeNode *left = lca(node->left, n1, n2);
    TreeNode *right = lca(node->right, n1, n2);
    if (left != NULL && right != NULL)   /// first condition
        return node;
    else if (left != NULL)               ///second condition
        return left;
    else
        return right;                    ///3rd condition
}

int solve(TreeNode *root,int valu)
{
    if(root==NULL)
    {
        return -0;
    }
    if(root->val == valu)
        return 1;
    int a  = solve(root->left,valu);
    int b  = solve(root->right,valu);
    if(!a && !b )
        return 0;
    else
        return a+b+1;
}

int findDistance(TreeNode* root,int a,int b)
{
    TreeNode *LCA = lca(root,a,b);
    int x = solve(LCA,a);
    int y = solve(LCA,b);
    return x+y-2;
}

int main()
{
     TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);

    return 0;
}


