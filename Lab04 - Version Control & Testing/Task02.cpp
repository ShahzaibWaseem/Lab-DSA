#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

bool moveMin(vector<int> &in, vector<int> &out){
	bool isSorted = true;
	sort(in.begin(), in.end());

	for (int i = 0; i < in.size(); i++){
		for (int j = 0; j < in.size(); j++){
			if (in[i] != out[i]){
				isSorted = false;
				break;
			}
			else
				isSorted = true;
		}
	}

	return isSorted;
}

bool testMoveMin(){
	vector<int> in, out;
	int randomNumber, temp;
	int arr[10];

	// Random Numbers to an Array then to the vector 'in'
	for (int i = 0; i < 10 ; i++){
		// generate vector with random numbers between 1 and 100
		arr[i] = rand() % 100 + 1;
		in.push_back(arr[i]);
	}
	cout << "Random values are stored in vector 'in' :" << endl;
	for (int i = 0; i < in.size(); i++)
		cout << in[i] << "\t";

	// Sorting the whole Vector
	sort(in.begin(), in.end());
	// Adding another element to the vector 'in' to keep its last element unsorted
	in.push_back(rand() % 100 + 1);


	// Copying the vector 'in' to another vector 'out'
	for (int i = 0; i < in.size(); i++)
		out.push_back(in[i]);

	// After completely sorting 'in' and then adding a random number at the end (last element unsorted)
	cout << endl << "Sorted Vector 'in' except the last element : " << endl;
	for (int i = 0; i < in.size(); i++)
		cout << in[i] << "\t";

	// Printing the copied vector 'out'
	cout << endl << "Copied Vector in to 'out' : " << endl;
	for (int i = 0; i < out.size(); i++)
		cout << out[i] << "\t";

	sort(out.begin(), out.end());

	// Sorting the vector 'out'
	cout <<endl<< "The Newly Created Vector 'out' is sorted : " << endl;
	for (int i = 0; i < out.size(); i++)
		cout << out[i] << "\t";
	cout << endl;

	// Calling the function implemented moveMin()
	return moveMin(in,out);
}

int main(){
	// to get a random value (argument is called seed)
	srand(time(NULL));

	cout << "TASK 02" << endl;

	if (testMoveMin())
		cout << "The Test Passed..." << endl;
	else
		cout << "The Test Failed..." << endl;
	system("PAUSE");
	return 0;
}