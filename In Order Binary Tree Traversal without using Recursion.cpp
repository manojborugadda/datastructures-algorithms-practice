#include <bits/stdc++.h>
#include<stack>
#include<iostream>
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
   if(root == NULL)
   {
       return;
   }
   stack<node *>s;
   s.push(root);
   while(s.empty()==false)
   {
       node *curr = s.top();
       cout<<curr->data<<" ";
       s.pop();
       if(curr->right)
       {
        s.push(curr->right);
       }
       if(curr->left)
       {
           s.push(curr->left);
       }
   }

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

    cout<<"\nInOrder Traversal of the binary  tree is : \n";
    PreOrder(root);

    return 0;
}
