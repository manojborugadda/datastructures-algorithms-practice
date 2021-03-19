#include <bits/stdc++.h>
#include<queue>
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

node *insert_node(node*root ,int data )  ///inserting the nodes------------
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

void LevelOrder(node *root)           ///Level Order Traversal function
{
    if(root == NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);

    while(q.empty()==false)
    {
        node *curr = q.front();
        cout<<curr->data<<" ";      /// // Print FRONT of queue and remove it from the queue
        q.pop();
        if(curr->left != NULL)       /// Enqueue left child
            q.push(curr->left);
        if(curr->right!=NULL)         ///Enqueue Right child
            q.push(curr->right);
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
    cout<<"Level Order Traversal of the binary  tree is :"<<" ";
    LevelOrder(root);
    return 0;
}


///  Time Complexity: O(n) where n is number of nodes in the binary tree
///  Space Complexity: O(n) where n is number of nodes in the binary tree





///******************mycodeschool YT channel reference*********
