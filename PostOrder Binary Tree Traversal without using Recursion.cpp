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

void PostOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<node *> s1,s2;
    s1.push(root);
    node * a;
    while(s1.empty() == false)
    {
        a = s1.top();
        s1.pop();
        s2.push(a);
        if(a->left)
            s1.push(a->left);
        if(a->right)
            s1.push(a->right);

    }

    while(s2.empty()==false)
    {
         a = s2.top();
         s2.pop();
         cout<<a->data<<" ";
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

    cout<<"\nPostOrder Traversal of the binary  tree is : \n";
    PostOrder(root);

    return 0;
}
