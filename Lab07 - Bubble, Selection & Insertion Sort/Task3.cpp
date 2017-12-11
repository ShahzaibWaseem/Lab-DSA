#include <iostream>
#include <vector>
#include <time.h>			// Used for clock() - Getting The Time
#include <algorithm>		// Used for swap() - Swapping Numbers
							// Also for sort() - Sorts in Ascending Order
							// Also for reverse() - reverses the Order of the Vector
#include <iomanip>			// Used for setw() - Alignment

using namespace std;

vector<int> BubbleSort(vector<int> Data);
vector<int> InsertionSort(vector<int> Data);
vector<int> SelectionSort(vector<int> Data);
vector<int> RandomVector(vector<int> Data, long VectorSize);
void Check(vector<int> Data, long VectorSize, string Order);
void Complexity(long VectorSize);

int main(int argc, char const *argv[]){
	srand(time(NULL));		// Seeding
	long VectorSize;

	VectorSize = 100;
	cout << endl << "Comparison of the Algos for " << VectorSize <<
		" Vector Size"<< endl;
	Complexity(VectorSize);

	VectorSize = 1000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Complexity(VectorSize);

	VectorSize = 10000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Complexity(VectorSize);

	VectorSize = 100000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	Complexity(VectorSize);

	VectorSize = 1000000;
	cout << endl << "Comparison of the Algos for " << VectorSize << 
		" Vector Size" << endl;
	//Complexity(VectorSize);
	cout << "I will Not perform this Comparison Because it will take alot of time" << endl;

	return 0;
}

void Complexity(long VectorSize){
	vector<int> Ascending, Descending;

	// Getting Random Vectors
	Ascending = RandomVector(Ascending, VectorSize);
	Descending = RandomVector(Descending, VectorSize);

	sort(Ascending.begin(), Ascending.end());		// Sorting the Ascending Vector
	sort(Descending.begin(), Descending.end());		// Sorting the Descending Vector in Ascensding Order
	reverse(Descending.begin(), Descending.end());	// Reversing the Ordered Vector(Descending)

	cout << endl << "Ascending Vector" << endl;
	Check(Ascending, VectorSize, "Ascending");		// Measuring times of the Algos

	cout << endl << "Descending Vector" << endl;
	Check(Descending, VectorSize, "Descending");	// Measuring times of the Algos

}

// Runs all The Sorting Algorithms and Prints their elapsed Times
void Check(vector<int> Data, long VectorSize, string Order){
	clock_t begin, end;
	double elapsed_secs;

	// BUBBLE SORT
	begin = clock();			// Initial Time
	Data = BubbleSort(Data);	// Sorting
	end = clock();				// Final Time
	
	// Calculating Elapsed Time
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Bubble Sort Running Time\t: " << elapsed_secs << endl;

	// SELECTION SORT
	if(!Order.compare("Descending"))
		reverse(Data.begin(), Data.end());		// reversing vector so that the sorted remains reversed

	begin = clock();			// Initial Time
	Data = SelectionSort(Data);	// Sorting
	end = clock();				// Final Time

	// Calculating Elapsed Time
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Selection Sort Running Time\t: " << elapsed_secs << endl;

	// INSERTION SORT
	if(!Order.compare("Descending"))			// reversing vector so that the sorted remains reversed 
		reverse(Data.begin(), Data.end());

	begin = clock();			// Initial Time
	Data = InsertionSort(Data);	// Sorting
	end = clock();				// Final Time

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