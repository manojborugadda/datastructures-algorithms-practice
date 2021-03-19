#include <bits/stdc++.h>
#include<queue>
using namespace std;

typedef struct BSTnode
{
    int data;
    BSTnode *left;
    BSTnode *right;
}node;

node *Getnewnode(int data)                    ///node creation -----------
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node*root ,int data )          ///inserting the nodes------------
{
    if(root == NULL)
    {
        root = Getnewnode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert_node(root->left,data);
    }
    else
    {
        root->right = insert_node(root->right,data);
    }

    return root;
}

void PreOrder(node *root)
    {
        if(root == NULL)         ///base condition
        {
            return;
        }
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

void InOrder(node *root)
{
    if(root == NULL)        ///base condition
        return ;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(node *root)
{
    if(root == NULL)   ///base condition
        return ;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root = NULL;
    root = insert_node(root,15);
    root = insert_node(root,10);
    root = insert_node(root,20);
    root = insert_node(root,8);
    root = insert_node(root,12);
    root = insert_node(root,17);
    root = insert_node(root,25);
    cout<<"\nPreOrder Traversal of the binary  tree is:  \n";
    PreOrder(root);
    cout<<"\nInOrder Traversal of the binary  tree is : \n";
    InOrder(root);
    cout<<"\nPostOrder Traversal of the binary  tree is : \n";
    PostOrder(root);
    return 0;
}


///  Time Complexity: O(n) where n is number of nodes in the binary tree
///  Space Complexity: O(n) where n is number of nodes in the binary tree





///******************mycodeschool YT channel reference*********
