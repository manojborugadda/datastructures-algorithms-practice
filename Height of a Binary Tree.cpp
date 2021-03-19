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

// we can find the height of the Tree by calculating MAXIMUM height of both Right subtree and Left sub tree or child and add 1 to the maximum
int FindHeight(node *root)
{
    if(root == NULL)
        {
            return -1;
        }
    else
    {
        return max( FindHeight(root->left) , FindHeight(root->right) ) + 1;
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
    cout<<"Height of the binary  tree is :"<<FindHeight(root)<<endl;
    return 0;
}



