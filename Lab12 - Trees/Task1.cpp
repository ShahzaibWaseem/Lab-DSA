#include <iostream>
using namespace std;

class Tree{
	struct BST_Node{
		int data;
		BST_Node* LeftChild;
		BST_Node* RightChild;
	};

	BST_Node* rootNode;

	// TASK 1
	BST_Node* insertNode(BST_Node* root, int element){
		if (root == NULL){
			root = new BST_Node;
			root -> data = element;
			root -> LeftChild = NULL;
			root -> RightChild = NULL;
		}
		else if (element < root -> data)
			root -> LeftChild = insertNode(root -> LeftChild, element);
		else
			root -> RightChild = insertNode(root -> RightChild, element);
	}

public:
	Tree(){
		rootNode = NULL;
	}

	void insertNode(int element){
		rootNode = insertNode(rootNode, element);
	}
};

int main () {
	Tree Node;

	Node.insertNode(72);
	Node.insertNode(66);
	Node.insertNode(144);
	return 0;
}