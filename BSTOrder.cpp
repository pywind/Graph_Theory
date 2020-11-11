#include <iostream>
#include <iomanip>

using namespace std;

struct BST {
	int ID;
	string name;
	float score;
	BST* right, * left, * parent;
}*Root;

void Init_BST() {
	Root = NULL;
}
BST* newNode(int id, string name, float sc) {
	BST* node = new BST;
	node->ID = id, node->name = name, node->score = sc;
	node->left = NULL, node->right = NULL;
	return node;
}
void insertNode(BST** Tree, int id, string name, float score) {
	BST* node, * parent, * current;
	// Create a Node to insert
	node = newNode(id, name, score);
	//parent of node is par
	parent = NULL;
	// current is root of Tree
	current = *Tree;
	while (current != NULL) {
		parent = current;
		if (current->ID > node->ID) current = current->left;
		else current = current->right;
	}// find the position of node in Tree
	node->parent = parent;

	if (parent == NULL) {
		*Tree = node;
	}
	else
		if (parent->ID > node->ID) {
			parent->left = node;
		}
		else parent->right = node;
}

BST* Tree_search(BST* root, int id)
{
	while (root != NULL)
	{
		if (id != root->ID)
			if (id < root->ID) root = root->left;
			else root = root->right;
		else return root;
	}
	return root;
}
void in_order(struct BST* root)
{
	if (root != NULL) {
		in_order(root->left);
		cout << root->ID << " ";
		in_order(root->right);
	}
}
void Info(BST* node) {
	cout << "Information of this ID: ";
	cout << node->ID << "\n" << node->name << endl;
	cout << "Score: " << setprecision(1) << fixed << node->score;
}
int main() {
	BST** Tree;
	Init_BST();
	Tree = &Root;
	insertNode(Tree, 50, "mine", 7.6);
	insertNode(Tree, 30, "perfect", 10.0);
	insertNode(Tree, 20, "lose", 3.0);
	insertNode(Tree, 40, "balance", 5.0);
	insertNode(Tree, 70, "good", 8.0);
	insertNode(Tree, 60, "under good", 7.0);
	insertNode(Tree, 80, "excellent", 9.0);

	// in_order(Root);

	BST* found = Tree_search(Root, 30);
	Info(found);
}