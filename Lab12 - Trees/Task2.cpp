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

	// TASK 2
	void in_Order_Traversal(BST_Node* root){
		if (root == NULL)
			return;

		in_Order_Traversal(root -> LeftChild);
		cout << root -> data << " ";
		in_Order_Traversal(root -> RightChild); 
	}

	BST_Node* search(BST_Node* root, int element){
		if(root = NULL)
			return NULL;

		else if (element < root -> data)
			return search(root -> LeftChild, element);

		else if (element > root -> data)
			return search(root -> RightChild, element);
		else if (element == root -> data)
			return root;

		else
			return root;
	}

public:
	Tree(){
		rootNode = NULL;
	}

	void insertNode(int element){
		rootNode = insertNode(rootNode, element);
	}

	void in_Order_Traversal(){
		in_Order_Traversal(rootNode);
		cout << endl;
	}

	void search(int element){
		rootNode = search(rootNode, element);
	}
};

int main () {
	Tree Node;

	Node.insertNode(110);
	Node.insertNode(1440);
	Node.insertNode(266);
	Node.insertNode(197);
	Node.insertNode(72);
	Node.insertNode(66);
	Node.insertNode(144);

	Node.in_Order_Traversal();
	return 0;
}