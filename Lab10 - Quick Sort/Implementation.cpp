#include <iostream>			// Used for swap() - swaps two elements of an Array
#include <iomanip>			// Used for setw() - Alignment

using namespace std;

void PrintVector(int* Data, int arr_size);
void QuickSort(int* Data, int head, int tail);
int Partition(int* Data, int first, int second);

int main(int argc, char const *argv[]){
	int Data[] = { 10, 12, 425, 644, 41, 0, 12 };
	// calculating the size of the array
	int arr_size = sizeof(Data) / sizeof(Data[0]);

	cout << "Original Array: \t";
	PrintVector(Data, arr_size);

	QuickSort(Data, 0, arr_size - 1);
	cout << endl << "Sorted Array: \t\t";
	PrintVector(Data, arr_size);
	return 0;
}

void QuickSort(int* Data, int head, int tail){
	if (head < tail){
		int temp = Partition(Data, head, tail);
		// Recursion with first half of partition
		QuickSort(Data, head, temp - 1);
		// Recursion with second half of partition
		QuickSort(Data, temp + 1, tail);
	}
}

int Partition(int* Data, int first, int second){
	int pivot, i, j;
	pivot = Data[first];
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

// Prints out the Array
void PrintVector(int* Data, int arr_size){
	for (int i = 0; i < arr_size; ++i){
		cout << setw(3) << Data[i] << " ";
	}
}