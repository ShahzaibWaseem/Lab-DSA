#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class MinimumHeap{
	int heap_size;				// Holds the size of the Heap
	vector <int> heap;			// Holds the Values
public:
	int top();					// Gets the root node without poping it
	void push(int element);		// inserts a new node to the Heap
	void pop();					// Deletes the root node from the Heap
	bool isEmpty();				// Returns true if the Heap is empty
	int size();					// tells the size of the Heap
	int height();				// tells the height of the Heap
	void buildHeap(int* array, int arraySize);	// builds a Heap from an array passed
	void print();				// prints out the Heap

	// Utitlty Functions
	int left(int element);		// returns the key of left child of the node
	int right(int element);		// returns the key of right child of the node
	int parent(int element);	// returns the key of parent of the node
	void heapProperty(int i);	// checks the heap property
	void heapify(int i);		// rotates nodes if Heap Property is violated
};

int MinimumHeap::left(int element){return (2*element) + 1;}

int MinimumHeap::right(int element){return (2*element) + 2;}

int MinimumHeap::parent(int element){return (element - 1)/2;}

void MinimumHeap::heapProperty(int i){
	int leftChild = left(i);
	int rightChild = right(i);
	int root = i;

	if (heap[leftChild] < heap[i] && leftChild < size())
		root = leftChild;

	if (heap[rightChild] < heap[root] && rightChild < size())
		root = rightChild;

	if (root != i){
		swap(heap[i], heap[root]);
		heapProperty(root);
	}
}

void MinimumHeap::heapify(int i){
	if (i && heap[parent(i)] > heap[i]){
		swap(heap[i], heap[parent(i)]);
		heapify(parent(i));
	}
}

int MinimumHeap::top(){
	if (size() != 0)
		return heap.at(0);
}

void MinimumHeap::push(int element){
	heap.push_back(element);
	heapify(size() - 1);
}

void MinimumHeap::pop(){
	if (size() == 0){
		cout << "Heap is Empty.\tcannot pop." << endl;
		return;
	}

	heap[0] = heap.back();
	heap.pop_back();

	heapProperty(0);
}

bool MinimumHeap::isEmpty(){return size() == 0;}

int MinimumHeap::size(){return heap.size();}

// height = log(base2)(n+1)-1
int MinimumHeap::height(){
	int height;
	height = log2(size() + 1) - 1;
	return height;
}

void MinimumHeap::buildHeap(int* array, int arraySize){
	for (int i = 0; i < arraySize; i++){
		push(array[i]);
	}
	cout << "Printing Heap created from an arry" << endl;
	print();
}

void MinimumHeap::print(){
	cout << endl << "Printing...\n\t\t| ";
	for (int i = 0; i < size(); i++)
		cout << heap[i] << " | ";
	cout << endl << endl;
}


int main(int argc, char const *argv[]){
	MinimumHeap heap;
	int array[] = {6,17,5,7,10,15,12};
	int arraySize = sizeof(array)/sizeof(int);

	heap.pop();
	cout << "is Empty : " << heap.isEmpty() << endl;
	cout << "Size is : " << heap.size()<< endl;
	cout << "The height of the Heap is : " << heap.height()<< endl; 
	heap.buildHeap(array, arraySize);
	
	cout << "is Empty : " << heap.isEmpty() << endl;
	cout << "Size is : " << heap.size()<< endl;
	cout << "The height of the Heap is : " << heap.height()<< endl;
	heap.push(100);

	heap.print();
	cout << "is Empty : " << heap.isEmpty() << endl;
	cout << "Size is : " << heap.size()<< endl;
	cout << "The height of the Heap is : " << heap.height()<< endl;

	return 0;
}