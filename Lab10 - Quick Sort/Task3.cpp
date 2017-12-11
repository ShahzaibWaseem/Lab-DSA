#include <iostream>			// Used for swap() - swaps two elements of an Array
#include <iomanip>			// Used for setw() - Alignment
#include <time.h>			// Used for srand() - Generate Random Numbers
#include <algorithm>		// Used for malloc() - Dynamic Memory Allocation

using namespace std;

int no_of_partitions = 0;

void QuickSort(int* Data, int head, int tail, int pivotValue);
int Partition(int* Data, int first, int second, int pivotValue);
int* RandomArray(int* Data, long ArraySize);
void CheckSizes(long ArraySize);

int main(int argc, char const *argv[]){
	srand(time(NULL));		// Seeding
	long ArraySize;

	ArraySize = 100;
	cout << endl << "Number of Partitions in QuickSort for " 
		<< ArraySize << " Array Size";
	CheckSizes(ArraySize);
	no_of_partitions = 0;

	ArraySize = 1000;
	cout << endl << "Number of Partitions in QuickSort for " 
		<< ArraySize << " Array Size";
	CheckSizes(ArraySize);
	no_of_partitions = 0;

	ArraySize = 10000;
	cout << endl << "Number of Partitions in QuickSort for " 
		<< ArraySize << " Array Size";
	CheckSizes(ArraySize);
	return 0;
}

void CheckSizes(long ArraySize){
	int *Data = (int *)malloc(ArraySize * sizeof(int));
	int middle = ArraySize / 2;
	
	no_of_partitions = 0;
	cout << endl << "\tFor First\t:\t";
	// Generating a Array of Random Numbers
	Data = RandomArray(Data, ArraySize);
	QuickSort(Data, 0, ArraySize - 1, 0);						// QUICK SORT
	cout << setw(6) << no_of_partitions;

	no_of_partitions = 0;
	cout << endl << "\tFor Median\t:\t";
	// Generating a Array of Random Numbers
	Data = RandomArray(Data, ArraySize);
	// Median only for even numbers
	QuickSort(Data, 0, ArraySize - 1, (2 * middle + 1) / 2);	// QUICK SORT
	cout << setw(6) << no_of_partitions;

	no_of_partitions = 0;
	cout << endl << "\tFor Last\t:\t";
	// Generating a Array of Random Numbers
	Data = RandomArray(Data, ArraySize);
	QuickSort(Data, 0, ArraySize - 1, ArraySize - 1);				// QUICK SORT
	cout << setw(6) << no_of_partitions;
}

void QuickSort(int* Data, int head, int tail, int pivotValue){
	if (head < tail){
		int temp = Partition(Data, head, tail, pivotValue);
		no_of_partitions++;
		// Recursion with first half of partition
		QuickSort(Data, head, temp - 1, pivotValue);
		// Recursion with second half of partition
		QuickSort(Data, temp + 1, tail, pivotValue);
	}
}

int Partition(int* Data, int first, int second, int pivotValue){
	int pivot, i, j;
	pivot = Data[pivotValue];
	i = first;			// i is the starting location of first partition
	j = second + 1;		// j is the starting location of second partition

	// Run the loop till i < j
	do{
		// Run till Data[i] > pivot or i is less than or equal to second
		do{
			i++;
		}while (Data[i] < pivot && i <= second);

		// Run till Data[j] > pivot
		do{
			j--;
		}while (Data[j] > pivot);

		// if i < j swap Data[i] and Data[j]
		if(i < j)
			swap(Data[i], Data[j]);
	}while(i < j);

	// Moving Pivot to its correct Location
	Data[first] = Data[j];
	Data[j] = pivot;

	return j;
}

// Generates a Array with Random Elements
int* RandomArray(int* Data, long ArraySize){
	int randomNumber = 0;
	for (int i = 0; i < ArraySize; ++i){
		randomNumber = rand() % 100 + 1;
		Data[i] = randomNumber;
	}
	return Data;
}