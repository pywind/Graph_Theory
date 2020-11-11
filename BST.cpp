#include <iostream>


using namespace std;

struct BST {
	int key;
	BST* right, * left, * parent;
}*Root;

void Init_BST() {
	Root = NULL;
}
void insertNode(BST** Tree, int k) {
	BST* node, * par, * current;
	// Create a Node to insert
	node = new BST;
	node->key = k, node->left = NULL, node->right = NULL;
	//parent of node is par
	par = NULL;
	// current is root of Tree
	current = *Tree;
	while (current != NULL) {
		par = current;
		if (current->key > node->key) current = current->left;
		else current = current->right;
	}// find the position of node in Tree
	node->parent = par;

	if (par == NULL) {
		*Tree = node;
	}
	else
		if (par->key > node->key) {
			par->left = node;
		}
		else par->right = node;
}
// Find the left & right most of BST
int LeftMostValue(BST* root) {
	if (root == NULL) return NULL;
	while (root->left != NULL) {
		root = root->left;
	}
	return root->key;
}
int RightMostValue(BST* root) {
	if (root == NULL) return NULL;
	while (root->right != NULL) {
		root = root->right;
	}
	return root->key;
}

BST* Tree_search(BST* root, int k)
{
	while (root != NULL)
	{
		if (k != root->key)
			if (k < root->key) root = root->left;
			else root = root->right;
		else return root;
	}
	return root;
}
void inorder(struct BST* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}
int main() {
	BST** Tree;
	Init_BST();
	Tree = &Root;
	insertNode(Tree, 50);
	insertNode(Tree, 30);
	insertNode(Tree, 20);
	insertNode(Tree, 40);
	insertNode(Tree, 70);
	insertNode(Tree, 60);
	insertNode(Tree, 80);
	inorder(Root);

	cout << "Search Tree " << Tree_search(Root, 30);
}