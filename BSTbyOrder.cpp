#include <iostream>

using namespace std;

struct BST {
	int key;
	BST* right, * left, * parent;
}*Root;

void Init_BST_Order()
{
	Root = NULL;
}

BST* newNode(BST* p, int k)
{
	BST* node = new BST;
	node->key = k;
	node->left = NULL; node->right = NULL;
	node->parent = p;
	return (node);
}

// Function to insert nodes in level order
BST* insertLevelOrder(int arr[], BST* p, BST* root,
	int i, int n)
{
	// Base case for recursion
	if (i < n)
	{
		BST* temp = newNode(p, arr[i]);
		root = temp;

		// insert left child
		root->left = insertLevelOrder(arr, root,
			root->left, 2 * i + 1, n);

		// insert right child
		root->right = insertLevelOrder(arr, root,
			root->right, 2 * i + 2, n);
	}
	return root;
}

void inorder(struct BST* node)
{
	if (node != NULL) {
		inorder(node->left);
		cout << node->key << " ";
		inorder(node->right);
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
	int n = 9;
	Init_BST_Order();
	Root = insertLevelOrder(arr, Root, Root, 0, n);
	inorder(Root);
}