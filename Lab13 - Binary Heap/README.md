# Lab 13: Binary Heap

## Tasks

Implement the Following functions while maintaining the basic property of Heap.

1. Top() : Gets the root Node (without Poping it)
2. Push(int) : Inserts a new Node to the Heap
3. Pop() : Deletes the root Node from the Heap
4. isEmpty() : Tells whether the Heap is empty
5. size() : Returns the size of the Heap
6. height() : Returns the height of the Heap (height = log2(n + 1) - 1)
7. buildHeap(array) : Builds a Heap from an array passed
8. print() : Prints out the Heap (Breadth-First Traversal)

Other Functions

9. left(int) : Returns the key (not value) of the left child of any node
10. right(int) : Returns the key (not value) of the right child of any node
11. parent(int) : Returns the key (not value) of parent of any node
12. heapProperty(int) & heapify(int) : checks the heap property