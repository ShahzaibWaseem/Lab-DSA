#include <iostream>
#include <vector>
#include <time.h>			// Used for clock() - Getting The Time
#include <algorithm>		// Used for swap() - Swapping Numbers
#include <iomanip>			// Used for setw() - Alignment

using namespace std;

vector<int> BubbleSort(vector<int> Data);
vector<int> InsertionSort(vector<int> Data);
vector<int> SelectionSort(vector<int> Data);
vector<int> RandomVector(vector<int> Data, long VectorSize);
void Check(long VectorSize);

int main(int argc, char const *argv[]){
	srand(time(NULL));		// Seeding
	long VectorSize;

	VectorSize = 100;
	cout << endl << "Comparison of the Algos for " << VectorSize <<
		" Vector Size"<< endl;
	Check(VectorSize);

	VectorSize = 1000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Check(VectorSize);

	VectorSize = 10000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Check(VectorSize);

	VectorSize = 100000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Check(VectorSize);

	VectorSize = 1000000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	//Check(VectorSize);
	cout << "I will Not perform this Comparison Because it will take alot of time" << endl;
	return 0;
}

// Runs all The Sorting Algorithms and Prints their elpsed Times
void Check(long VectorSize){
	vector<int> BubbleVector, SelectionVector, InsertionVector;
	clock_t begin, end;
	double elapsed_secs;

	// BUBBLE SORT
	// Generating a Vector of Random Numbers
	BubbleVector = RandomVector(BubbleVector, VectorSize);

	begin = clock();		// Initial Time
	BubbleVector = BubbleSort(BubbleVector);	// Sorting
	end = clock();			// Final Time
	
	// Calculating Elapsed Time
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Bubble Sort Running Time\t: " << elapsed_secs << endl;

	// SELECTION SORT
	// Again Generating a Vector of Random Numbers
	SelectionVector = RandomVector(SelectionVector, VectorSize);

	begin = clock();		// Initial Time
	SelectionVector = SelectionSort(SelectionVector);	// Sorting
	end = clock();			// Final Time

	// Calculating Elapsed Time
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Selection Sort Running Time\t: " << elapsed_secs << endl;

	// INSERTION SORT
	// Again Generating a Vector of Random Numbers
	InsertionVector = RandomVector(InsertionVector, VectorSize);

	begin = clock();		// Initial Time
	InsertionVector = InsertionSort(InsertionVector);	// Sorting
	end = clock();			// Final Time

	// Calculating Elapsed Time
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Insertion Sort Running Time\t: " << elapsed_secs << endl;
}

vector<int> BubbleSort(vector<int> Data){
	for (int i = Data.size() - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (Data[j] > Data[j + 1]){
				swap(Data[j], Data[j + 1]);
			}
		}	
	}

	return Data;
}

vector<int> InsertionSort(vector<int> Data){
	int j = 0;
	for (int i = 1; i < Data.size(); i++){
		int key = Data[i];
		j = i - 1;
		while (j >= 0 && Data[j] > key){
			Data[j + 1] = Data[j];
			j--;
		}
		Data[j + 1] = key;
	}

	return Data;
}

vector<int> SelectionSort(vector<int> Data){
	for (int i = Data.size() - 1; i > 0; i--){
		int highest = i;
		for (int j = 0; j < i; j++){
			if (Data[j] > Data[highest]){
				swap(Data[j], Data[highest]);
			}
		}	
	}

	return Data;
}

// Generates a Vector of Random Numbers
vector<int> RandomVector(vector<int> Data, long VectorSize){
	int randomNumber = 0;
	for (int i = 0; i < VectorSize; ++i){
		randomNumber = rand() % 100 + 1;
		Data.push_back(randomNumber);
	}

	return Data;
}