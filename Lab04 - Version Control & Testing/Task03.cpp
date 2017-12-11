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
		if (in[i] != out[i]){
			isSorted = false;
			break;
		}
		else
			isSorted = true;
	}
	return isSorted;
}

bool testMoveMin(){
	vector<int> in, out;
	int randomNumber, temp;
	int arr[100000];

	// Random Numbers to an Array then to the vector 'in'
	for (int i = 0; i < 100000; i++){
		// generate vector with random numbers between 1 and 100
		arr[i] = rand() % 100 + 1;
		in.push_back(arr[i]);
	}

	// Sorting the whole Vector
	sort(in.begin(), in.end());
	// Adding another element to the vector 'in' to keep its last element unsorted
	in.push_back(rand() % 100 + 1);


	// Copying the vector 'in' to another vector 'out'
	for (int i = 0; i < in.size(); i++)
		out.push_back(in[i]);

	// Sorting the vector 'out'
	sort(out.begin(), out.end());

	// Calling the function implemented moveMin()
	return moveMin(in, out);
}

int main(){
	double best = 0.0, worst = 0.0;
	double temp = 0.0;
	double avg = 0.0 , sum = 0.0;
	double elapsed_secs;
	clock_t begin, end;

	srand(time(NULL));

	for (int i = 0; i < 100; i++){
		// measure the time at the start of the program (nearly zero)
		begin = clock();
		// Calling the Implemented function
		testMoveMin();
		// measuring the time elapsed after the function call
		end = clock();

		// Formula to find the time taken between first measure of time and the last measure
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "Test Number " << i + 1 << "\t:\t" << elapsed_secs << endl;
		

		temp = elapsed_secs;
		sum += temp;		// Sum to find avg

		// checking for the best and worst time
		if (temp > best)
			best = temp;

		// This is to get the worst case started
		worst = temp;
		if (temp < worst)
			worst = temp;
	}
	avg = sum / 100;

	cout << endl << endl;
	cout << "The Best Running Time is : " << best << endl;
	cout << "The Worst Running Time is : " << worst << endl;
	cout << "The Average Running Time is : " << avg << endl;
	cout << endl << endl;

	system("PAUSE");
	return 0;
}