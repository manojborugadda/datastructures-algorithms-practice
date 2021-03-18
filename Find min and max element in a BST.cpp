#include <bits/stdc++.h>
using namespace std;

typedef struct BSTnode
{
    int data;
    BSTnode *left;
    BSTnode *right;
}node;

node *Getnewnode(int data)  /////////node creation -----------
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node*root ,int data )  //////inserting the nodes------------
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

int find_min(node* root) ////////function for finding min element in the BST--------------
{
    if(root==NULL)
    {
        cout<<"Tree is empty: \n";
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }

    return find_min(root->left);
}


int find_max(node*root) ////////function for finding min element in the BST--------------
{
    if(root==NULL)
    {
        cout<<"Tree is empty: \n";
        return -1 ;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }

    return find_max(root->right);
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

    cout<<"minimum element in the BST is :"<<find_min(root)<<endl;
    cout<<"maximum element in the BST is :"<<find_max(root);
    return 0;
}



