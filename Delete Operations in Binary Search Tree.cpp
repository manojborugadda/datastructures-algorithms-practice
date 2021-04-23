/// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

/// program to demonstrate delete operation in binary search tree
/*
When we delete a node, three possibilities arise.

1) Node to be deleted is the LEAF: Simply remove from the tree.

2) Node to be deleted has only ONE child: Copy the child to the node and delete the child

3) Node to be deleted has TWO children: Find in-order successor of the node.
   Copy contents of the in-order successor to the node and delete the in-order successor.
   Note that in-order predecessor can also be used. */

#include<bits/stdc++.h>
using namespace std;
typedef struct BSTnode
{
    int data;
    BSTnode *left;
    BSTnode *right;
}Node;

/// A utility function to create a new BST node

Node *newNode(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void InOrder(Node *root)   /// In-order traversal
{
    if(root == NULL)        ///base condition
        return ;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

///A utility function to insert a new node with given data

Node *insert_node(Node *root,int data)
{
    if(root ==NULL)
    {
        return newNode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert_node(root->left,data);
    }
    else
    {
        //(data > root->data)
        root->right = insert_node(root->right,data);
    }
    return root;
}

/// A utility function to find the minimum value in a particular tree

Node *minValue(Node* root_node)
{
    Node *curr = root_node;
    while(curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

///Now we have a binary search tree and a NODE which has to deleted,this function deletes the node and returns the new root

Node *delete_node(Node *root,int data)
{
    if(root == NULL)
        return root;

    /// searching for the key if it in the left sub tree or right sub tree
    if(data < root->data)
        root->left = delete_node(root->left,data);
    else if(data > root->data)
        root->right = delete_node(root->right,data);
    else
    {
        /// Node to be deleted is the LEAF
        if(root->left == NULL && root->right ==NULL)
        {
            return NULL;

        }
         /// Node to be deleted has only ONE child
        if(root->left == NULL)
        {
            Node *temp =  root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL)
        {
            Node *temp1 = root->left;
            free(root);
            return temp1;
        }

        else
        {
             /// node with two children
             Node *temp = minValue(root->right);
             root->data = temp->data; /// copying the minimum element in the right sub tree with the root node
             root->right = delete_node(root->right,temp->data); /// deleting the  minimum node which is copied
        }

    }

        return root;

}


/// driver code


int main()
{
    Node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    cout<<"Inorder traversal of the given tree :\n";
    InOrder(root);
    cout<<"\n";
    root = delete_node(root,20);
    cout<<"Inorder traversal of the given tree after deleting 20 :\n";
    InOrder(root);

    cout << "\nDelete 30\n";
    root = delete_node(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    InOrder(root);

    cout << "\nDelete 50\n";
    root = delete_node(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    InOrder(root);
    return 0;

}
