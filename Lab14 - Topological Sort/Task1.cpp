#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
public:
	/* DATA MEMBERS */
	int number_of_vertices;						// contains the number of vertices
	list<int> *adjecent;						// contains the out going connections
	vector<int> Output;							// contains the topologically sorted Graph

	/* FUNCTIONS */
	Graph(int number_of_vertices);				// Constructor
	void createGraph();							// Asks for node connections
	void addEdge(int node1, int node2);
	void TopologicalSort();						// Implementation of Topological Sort
	void print();								// prints out the graph
};

Graph::Graph(int number_of_vertices){
	this->number_of_vertices = number_of_vertices;
	adjecent = new list<int>[number_of_vertices];
}

void Graph::createGraph(){
	int node1, node2;
	for (int i = 0; i < number_of_vertices; i++){
		cout << "Enter the Node Connection : ";
		cin >> node1 >> node2;
		addEdge(node1, node2);
	}
}

void Graph::addEdge(int node1, int node2){adjecent[node1].push_back(node2);}

void Graph::TopologicalSort(){ 
	vector<int> inDegree(number_of_vertices, 0);// initializing as zero
	queue<int> holdingQueue;

	// Traverses the Adjecent list; fills inDegree vector
	for (int i = 0; i < number_of_vertices; ++i){
		list<int>::iterator itr;
		for (itr = adjecent[i].begin(); itr != adjecent[i].end(); itr++)
			inDegree[*itr]++;
	}

	// when the inDegree of a Node is 0 add to queue
	for (int i = 0; i < number_of_vertices; ++i){
		if (inDegree[i] == 0)
			holdingQueue.push(i);
	}

	while(!holdingQueue.empty()){
		// Dequeue Operation
		int temp = holdingQueue.front();
		holdingQueue.pop();
		Output.push_back(temp);

		list<int>::iterator itr;
		for (itr = adjecent[temp].begin(); itr != adjecent[temp].end(); itr++){
			inDegree[*itr]--;
			if (inDegree[*itr] == 0)
				holdingQueue.push(*itr);
		}
	}
}

void Graph::print(){
	for (int i = 0; i < number_of_vertices; ++i)
		cout << Output[i] << " ";
	cout << endl;
}

int main(int argc, char const *argv[]){
	int number = 0;

	cout << endl << "Enter the Number of Vertices : ";
	cin >> number;
	Graph graph(number);
	
	graph.createGraph();

    cout << endl << "Following is a Topological Sort of " << endl;
    graph.TopologicalSort();
    graph.print();
	return 0;
}

