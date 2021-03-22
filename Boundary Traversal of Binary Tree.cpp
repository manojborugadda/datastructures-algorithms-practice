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


void print_left_boundary(TreeNode* node)          /// here traverse in PRE-order manner
{
    if (node == NULL)
        return;
    if (node->left)
    {
        cout << node->val << " ";
        print_left_boundary(node->left);
    }
    else if (node->right)
    {
        cout << node->val << " ";
        print_left_boundary(node->right);
    }
}

void print_right_boundary(TreeNode* node)       /// here traverse in POST-order manner
{
    if (node == NULL)
        return;
    if (node->right)
    {
        print_right_boundary(node->right);
        cout << node->val << " ";
    }
    else if (node->left)
    {
        print_right_boundary(node->left);
        cout << node->val << " ";
    }
}

void print_leaves(TreeNode* node)               /// here traverse in IN-order manner
{
    if (node == NULL)
        return;

    print_leaves(node->left);
    if (node->left == NULL && node->right == NULL)
        cout << node->val << " ";
    print_leaves(node->right);
}

void boundary_traversal(TreeNode *root)
{
    if (root == NULL)
       return;
    cout << root->val << " ";
    print_left_boundary (root->left);
    print_leaves (root->left);
    print_leaves (root->right);
    print_right_boundary (root->right);
}

int main()
{   TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->left->right = new TreeNode('K');
    root->left->left->right->left = new TreeNode('N');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('M');
    root->right->right = new TreeNode('C');
    root->right->right->left = new TreeNode('B');
    root->right->right->left->left = new TreeNode('R');

     cout << "Boundary Traversal of the tree: ";
     boundary_traversal(root);

    return 0;
}


