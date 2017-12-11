#include <iostream>
#include <algorithm>		// Used for malloc() - Dynamic Array creation
#include <iomanip>			// Used for setw() - Alignment
#include <time.h>			// Used for clock() - Getting The Time

using namespace std;

void AvgTime(long ArraySize);
void Mergesort(int *Data, int arr_size);
void Merge(int *OriginalArray, int *LeftArray, int LeftSize, int *RightArray, int RightSize);
void PrintVector(int *Data, int arr_size);
int* RandomArray(int* Data, long ArraySize);

int main(int argc, char const *argv[]){
	srand(time(NULL));		// Seeding
	long ArraySize;

	ArraySize = 100;
	cout << endl << "Average Time taken by MergeSort for " << ArraySize <<
		" Array Size"<< endl;
	AvgTime(ArraySize);

	ArraySize = 1000;
	cout << endl << "Average Time taken by MergeSort for " << ArraySize << 
		" Array Size" << endl;
	AvgTime(ArraySize);

	ArraySize = 10000;
	cout << endl << "Average Time taken by MergeSort for " << ArraySize << 
		" Array Size" << endl;
	AvgTime(ArraySize);

	ArraySize = 100000;
	cout << endl << "Average Time taken by MergeSort for " << ArraySize << 
		" Array Size" << endl;
	AvgTime(ArraySize);

	ArraySize = 1000000;
	cout << endl << "Average Time taken by MergeSort for " << ArraySize << 
		" Array Size" << endl;
	//AvgTime(ArraySize);
	cout << endl << "Not Going to Run this because Arrays crash for size of " << ArraySize << endl;

	return 0;
}

void AvgTime(long ArraySize){
	int *Data = (int *)malloc(ArraySize*sizeof(int));
	clock_t begin, end;
	double elapsed_secs, sum = 0.0;

	// MERGE SORT
	// Generating a Array of Random Numbers
	Data = RandomArray(Data, ArraySize);

	
	for (int i = 0; i < 100; ++i){
		begin = clock();				// Initial Time
		Mergesort(Data, ArraySize);		// Sorting
		end = clock();					// Final Time

		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		sum += elapsed_secs;
	}
	
	cout << "Merge Sort Running Time\t: " << sum / 100.0 << endl;
}

int* RandomArray(int* Data, long ArraySize){
	int randomNumber = 0;
	for (int i = 0; i < ArraySize; ++i){
		randomNumber = rand() % 100 + 1;
		Data[i] = randomNumber;
	}

	return Data;
}

// return type is void because data is sent using pointers
void Merge(int *OriginalArray, int *LeftArray, int LeftSize, int *RightArray, int RightSize){
	// Looping variables
	int i = 0, j = 0, k = 0;

	// Breaking OriginalArray into two Arrays
	while (i < LeftSize && j < RightSize){
		if (LeftArray[i] < RightArray[j])
			OriginalArray[k++] = LeftArray[i++];
		else
			OriginalArray[k++] = RightArray[j++];
	}
	// saving the LeftArray to the OriginalArray
	while (i < LeftSize)
		OriginalArray[k++] = LeftArray[i++];
	
	// saving the RightArray to the OriginalArray
	while (j < RightSize)
		OriginalArray[k++] = RightArray[j++];
}

// return type is void because data is sent using pointers 
void Mergesort(int *Data, int arr_size){
	// if size is less than 2 just return
	if (arr_size < 2)
		return;
	
	int mid = arr_size / 2;

	// Dynamically creating two Arrays
	int *left = (int *)malloc(mid*sizeof(int));
	int *right = (int *)malloc(sizeof(int)*(arr_size - mid));
	
	// Breaking Data into two Arrays
	for (int i = 0; i < mid; i++)
		left[i] = Data[i];
	
	for (int i = mid; i<arr_size; i++)
		right[i - mid] = Data[i];
	
	// Calling Functions
	Mergesort(left, mid);
	Mergesort(right, arr_size - mid);
	Merge(Data, left, mid, right, arr_size - mid);
}

// Prints out the Array
void PrintVector(int *Data, int arr_size){
	for (int i = 0; i < arr_size; ++i){
		cout << setw(3) << Data[i] << " ";
	}
}