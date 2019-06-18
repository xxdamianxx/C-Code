#include <iostream>

using namespace std;

struct Node
{
    long data;
    Node* left;
    Node* right;
};

void insert(Node* root, long value)
{
    Node* newItem = new Node();
    newItem->data = value;
    newItem->left = NULL;
    newItem->right = NULL;
    
    Node* curr = root;
    Node* prev = curr;
    while (curr != NULL)
    {
        prev = curr;
        if (value <= root->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    
    if (value <= prev->data)
    {
        prev->left = newItem;
    }
    else
    {
        prev->right = newItem;
    }
}

void print (Node* root)
{
    if (root != NULL)
    {
        print(root->left);
        cout  << root->data << " ";
        print(root->right);
    }
}

int main()
{
    Node* tree = new Node();
    tree->data = 5;
    tree->left = NULL;
    tree->right = NULL;
    
    insert(tree, 3);
    insert(tree, 7);
    
    print(tree);
    
    return 0;
}