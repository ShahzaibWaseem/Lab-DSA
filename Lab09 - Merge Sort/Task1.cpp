#include <iostream>
#include <algorithm>		// Used for malloc() - Dynamic Array creation
#include <iomanip>			// Used for setw() - Alignment

using namespace std;

void Mergesort(int *Data, int arr_size);
void Merge(int *OriginalArray, int *LeftArray, int LeftSize, int *RightArray, int RightSize);
void PrintVector(int *Data, int arr_size);

int main(int argc, char const *argv[]){
	int Data[] = { 10, 12, 425, 644, 41, 0, 12 };
	// calculating the size of the array
	int arr_size = sizeof(Data) / sizeof(Data[0]);

	cout << "Original Array: " << endl;
	PrintVector(Data, arr_size);
	cout << endl;

	Mergesort(Data, arr_size);
	cout << "Sorted Array: " << endl;
	PrintVector(Data, arr_size);

	return 0;
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