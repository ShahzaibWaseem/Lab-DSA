#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void moveDisk(stack <int> &moveFrom, stack <int> &moveTo);
void moveTowerofHanoi(int NumberOfDisks, stack <int> &source, stack <int> &spare, stack <int> &destination);

// Used to get the number of moves ; Global Variable
int NumberOfMoves = 0;

int main(int argc, char const *argv[]){
	int NumberOfDisks;
	stack <int> source, spare, destination;

	// prompting user for number of disks
	cout << endl << "\tEnter the Number of Disks : ";
	cin >> NumberOfDisks;

	cout << endl << "\tTowers:" << endl;
	cout << "\t\tTower 1: " << "\t" << &source << endl;
	cout << "\t\tTower 2: " << "\t" << &spare << endl;
	cout << "\t\tTower 3: " << "\t" << &destination << endl << endl;

	// pushing all disks in the source stack
	for (int i = 0; i < NumberOfDisks; ++i)
		source.push(i);

	moveTowerofHanoi(NumberOfDisks, source, spare, destination);

	cout << endl << "\tNumber of moves : " << NumberOfMoves << endl;
	return 0;
}

void moveTowerofHanoi(int NumberOfDisks, stack <int> &source, stack <int> &spare, stack <int> &destination){
	// edge case if number of disks = 1 because there is no need for recursion
	if(NumberOfDisks == 1){
		// just moving disk 1 from source stack to destination stack
		moveDisk(source, destination);
		cout << "\tMoving Disk #" << "\t" << NumberOfDisks << "\t(" << &source << " -> " << &destination << ")" << endl;
	}

	// for other number of disks
	else{
		// recursive calling
		// note that the order of stacks in the function call is changed
		moveTowerofHanoi(NumberOfDisks - 1, source, destination, spare);
		//moving disk from source stack to destination stack
		moveDisk(source, destination);
		cout << "\tMoving Disk #" << "\t" << NumberOfDisks << "\t(" << &source << " -> " << &destination << ")" << endl; 
		// recursive calling
		// note that the order of stacks in the function call is changed
		moveTowerofHanoi(NumberOfDisks - 1, spare, source, destination);
	}
}


void moveDisk(stack <int> &moveFrom, stack <int> &moveTo){
	// moving the top of moveFrom stack to moveTo
	moveTo.push(moveFrom.top());
	// poping the top of moveFrom stack
	moveFrom.pop();
	NumberOfMoves++;
}