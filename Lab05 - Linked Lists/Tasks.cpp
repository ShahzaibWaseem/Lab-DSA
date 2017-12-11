#include <iostream>

using namespace std;

class node{
public:
	int value;
	node *next;
};

class list{
public:
	// This Pointer is the Head Pointer to the Linked List
	node* head;
	// This will give the size of the Linked List at the point
	int size;

	list(){
		head = NULL;
	}

	void insert_at_beginning(int new_value){
		node* tempNode = new node;		// creating a temporary node to add the new value

		size++;
		tempNode->value = new_value;	// using the "value" field in node to save the data
		tempNode->next = head;			// using the "next" pointer field to save the address of head
		head = tempNode;				// saving the address of tempNode in head so a new node is added at the front of the list
	}

	void insert_at_loc(int location, int new_value){
		// Index cannot be negative
		if (location < 0)
			cout << "The Index is negative" << endl << "exiting Function" << endl;
		// If index == 0 then insert it into the first of the Linked List
		else if (location == 0)
			insert_at_beginning(new_value);
		// Print out a statement if the location exceeds the size of the Linked List
		else if (size < location)
			cout << "The Location is out of the Linked List" << endl;
		
		else{
			node* previousNode = new node;
			node* currentNode = new node;
			node* tempNode = new node;

			currentNode = head;					// "currentNode" equals the start of the Linked List
			for (int i = 0; i < location; i++){
				previousNode = currentNode;		// previousNode becomes the currentNode for the next iteration
				currentNode = currentNode->next;// Itrating "currentNode"
			}

			tempNode->value = new_value;		// Storing the value in a temp node
			previousNode->next = tempNode;		// inserting the tempNode into the next of previousNode
			size++;
			tempNode->next = currentNode;		// saving the address of currentNode in the tempNode .now tempNode is a part of the List
		}
	}

	void del(int location){
		node* previousNode = new node;
		node* currentNode = new node;

		currentNode = head;							// "currentNode" equals the start of the Linked List
		if (location == 0)
			head = head->next;						// if location is 0 then just move the head's starting position one step ahead
		
		else{
			for (int i = 1; i < location; i++){
				previousNode = currentNode;			// previousNode becomes the currentNode for the next iteration
				currentNode = currentNode->next;	// Itrating "currentNode"
			}
			previousNode->next = currentNode->next;	// saving the address of the "next" of currentNode into the "next" of the previousNode
		}
	}

	void display(){
		node* displayNode;

		displayNode = head;							// "displayNode" equals the start of the Linked List

		cout << "head -> ";
		while (displayNode != NULL){
			cout << displayNode->value << " -> ";
			displayNode = displayNode -> next;		// Iterating displayNode till displayNode == NULL (end of the Linked List)
		}
		cout << "NULL" << endl;
	}

	// This funtion was solved each time the Linked List was appended
	void count(){
		cout << "The Size of the Linked List is : " << size << endl;
	}


	// MENU OPTIONS

	// Ask for number of numbers you want to enter and then adding numbers to the LinkedList
	void option1(){
		int number_of_nodes, number;
		cout << "How many Numbers do you want to add at the begining? : ";
		cin >> number_of_nodes;

		for (int i = 0; i < number_of_nodes; i++){
			cout << "Enter Number : " << i + 1 << " : ";
			cin >> number;
			insert_at_beginning(number);
		}
	}
	// Ask User for a number and then add it to the 3rd Location
	void option2(){
		int n;

		cout << "Enter the Number which you want to add at the node 3 : ";
		cin >> n;
		insert_at_loc(3, n);
	}
	// display the LinkedList
	void option3(){
		display();
	}
	// Delete a node from the LinkedList and then display it
	void option4(){
		int location;
		cout << "Which node you want to delete? : ";
		cin >> location;

		if (location > size)
			cout << "Deletion Failed\nYou are trying to access an index out of bound" << endl;
		else{
			cout << "Deletion Successful" << endl;
			del(location);
		}
		cout << "After trying Deletion : " << endl;
		display();

	}

	// This option just counts the number of nodes in the LinkedList
	void option5(){
		count();
	}
};

int main(){
	list LinkedList;
	int option;

	//Below is the menu from which user can select option
	cout << "What do you want to do with your Linked List" << endl << endl;
	cout << "1: Insert numbers in nodes (n times)" << endl;
	cout << "2: Insert number at the 3rd position" << endl;
	cout << "3: Display all nodes in above steps" << endl;
	cout << "4: Delete a node" << endl;
	cout << "5: Count the number of nodes" << endl << endl;
	cout << "OR 0 to break" << endl;
	
	// Infinite Loop unless 0 is typed
	while (true){
		cout << "> ";
		cin >> option;

		if (option == 1)
			LinkedList.option1();

		if (option == 2){
			if (LinkedList.size < 3)
				cout << "You cannot add any value at 3rd node\nAs you linked list is small than 3" << endl;
			else
				LinkedList.option2();
		}

		if (option == 3)
			LinkedList.option3();

		if (option == 4){
			if (LinkedList.size == 0)
				cout << "You can not delete a node because the Linked List is empty" << endl;
			else
				LinkedList.option4();
		}

		if (option == 5)
			LinkedList.option5();

		if (option == 0)
			break;
	}
	system("PAUSE");
	return 0;
}