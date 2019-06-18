#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right= insert(root->right, value);
        }
    }
    return root;
}

void traverse (Node* root)
{
    if (root != NULL)
    {
        traverse(root->left);
        cout  << root->data << " ";
        traverse(root->right);
    }
}

void displayInOrder(Node* root)
{
    traverse(root);
    cout << endl;
}

void displayTree(Node* root, int level, int direction)
{
    if (root != NULL)
    {
        displayTree(root->right, level+1, 1);
        
        for (int i = 0; i < level-1; i++)
        {
            cout << "   ";
        }
        if (level > 0 )
        {
            if (direction == 1)
            {
                cout << " /--";
            }
            else
            {
                cout << " \\--";
            }
        }

        cout << root->data;
        cout << endl;
        level++;
        
        displayTree(root->left, level, -1);
    }
}

void drawTree(Node* root)
{
    displayTree(root, 0, 0);
    cout << endl << endl;
}

bool search(Node* root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    else
    {
        if (root->data == value)
        {
            return true;
        }
        else if (value < root->data)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }
}

bool isBST(Node* root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        bool levelOK = true;
        if (root->left != NULL && root->left->data > root->data)
        {
            levelOK = false;
        }
        if (root->right != NULL && root->right->data <= root->data)
        {
            levelOK = false;
        }
        return levelOK && isBST(root->left) && isBST(root->right);
    }
}

int findMin(Node* root)
{
    Node* copy = root;

    while (copy->left != NULL)
    {
        copy = copy->left;
    }

    int result = copy->data;
    delete copy;

    return result;

}

int findMax(Node* root)
{
    Node* copy = root;

    while (copy->right != NULL)
    {
        copy = copy->right;
    }

    int result = copy->data;
    delete copy;

    return result;

}

void remove(Node* root, int value)
{
    Node* copy = root;
    Node* parent = copy;
    int lastMove = 0;
    while (copy->data != value)
    {
        parent = copy;
        if (value < copy->data)
        {
            copy = copy->left;
            lastMove = -1;
        }
        else if (value > copy->data)
        {
            copy = copy->right;
            lastMove = 1;
        }
    }

    if (copy->left == NULL && copy->right == NULL)
    {
        // No children, just remove
        if (lastMove == -1)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        delete copy;
    }
    else if (copy->left != NULL && copy->right == NULL)
    {
        // Left child only
        Node* leftSubtree = copy->left;

        if (lastMove == -1)
        {
            parent->left = leftSubtree;
        }
        else
        {
            parent->right = leftSubtree;
        }
        delete copy;
    }
    else if (copy->left == NULL && copy->right != NULL)
    {
        // Right child only
        Node* rightSubtree = copy->right;
        if (lastMove == -1)
        {
            parent->left = rightSubtree;
        }
        else
        {
            parent->right = rightSubtree;
        }
        delete copy;
    }
    else
    {
        // Both children are present
        Node* successor = copy->right;

        while (successor->left != NULL)
        {
            successor = successor->left;
        }

        int temp = successor->data;

        remove(root, successor->data);

        copy->data = temp;
    }
}

Node* successor(Node* root, int value)
{
    Node* copy = root;

    if (copy != NULL)
    {
        while (copy != NULL && copy->data != value)
        {
            if (value < copy->data)
            {
                copy = copy->left;
            }
            else if (value > copy->data)
            {
                copy = copy->right;
            }
        }
        if (copy != NULL && copy->right != NULL)
        {
            copy = copy->right;
            
            while (copy->left != NULL)
            {
                copy = copy->left;
            }
            return copy;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

// Sometimes, when searching for a particular value in a tree, it is useful to return a pointer to the node that contains the value, instead of just True or False. The function below should return a pointer to the node that contains the given value. If the value does not appear in the tree, your function should return NULL.

Node* findNode(Node* root, int value)
{
    // Your code here
}

// The function below takes a pointer to the root of a tree, as well as a value, and returns the number of times the value occurs in the tree rooted at root.

int occurrences(Node* root, int value)
{
    // Your code here
}

int main()
{
	// Start a new empty tree
    Node* tree = NULL;
    
	// Insert some numbers into it
    tree = insert(tree, 5);
    tree = insert(tree, 2);
    tree = insert(tree, 7);
    tree = insert(tree, 1);
    tree = insert(tree, 3);
    tree = insert(tree, 6);
    tree = insert(tree, 8);
    tree = insert(tree, 5);
    tree = insert(tree, 5);
    tree = insert(tree, 5);
    
	// Visualize the tree
    drawTree(tree);
    
	// Look for the number 7 in the tree
	Node* N = findNode(tree, 7);
    
    if (N != NULL)
    {
        cout << "7 is Found" << endl;
    }
    else
    {
        cout << "7 is Found" << endl;
    }
	
    // For the values between 1 and 8, how many times does each one occur in the tree?
    for (int i = 1; i <= 8; i++)
    {
        cout << i << ": " << occurrences(tree, i) << endl;
    }
    
    // Output should be:
	// 7 is Found
	// 0: 0
	// 1: 1
	// 2: 1
	// 3: 1
	// 4: 0
	// 5: 4
	// 6: 1
	// 7: 1
	// 8: 1
    
    return 0;
}