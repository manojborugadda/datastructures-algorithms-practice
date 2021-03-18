#include <bits/stdc++.h>
using namespace std;

typedef struct BST
{
    int data;
    BST *left;
    BST *right;
}BSTnode;

BSTnode *Getnewnode(int data)  // function to create a new NODE in Heap-----------
{
    BSTnode *new_node = (BSTnode*)malloc(sizeof(BSTnode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// inserting elements into the BST and we will return the ROOT node

BSTnode *Insert(BSTnode *root,int data)
{
    if(root == NULL)  ///empty tree
    {
        root = Getnewnode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(BSTnode *root,int data)
{
    if(root ==NULL)
    {
        return false;
    }
    else if(data == root->data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
{
    BSTnode *root = NULL;
    root = Insert(root,15);
    root =  Insert(root,10);
     root =  Insert(root,20);
      root =  Insert(root,25);
       root =  Insert(root,8);
        root =  Insert(root,12);

        int number;
        cout<<"bro enter the number: ";
        cin>>number;
        if(Search(root,number) ==true)
        {
            cout<<"we found the number in the tree\n";
        }
       else
       {
           cout<<"not found \n";
       }

    }
       return 0;
}




