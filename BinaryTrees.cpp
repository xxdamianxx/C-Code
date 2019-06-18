#include <iostream>

using namespace std;

struct Node
{
    long data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, long value)
{
	Node* newItem = new Node();
	newItem->data = value;
	newItem->left = NULL;
	newItem->right = NULL;

	if (root == 0)
	{
		root = newItem;
		return root;
	}

	Node*curr, *prev;
	curr = prev = root;

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
	return root;
}

void print (Node* root)
{
	if (!root)
	{
		return;
	}

	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

int main()
{
    Node* tree = NULL;
    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 8);
    tree = insert(tree, 1);
    tree = insert(tree, 6);
    tree = insert(tree, 4);
    tree = insert(tree, 7);
    
    print(tree);
        
    return 0;
}