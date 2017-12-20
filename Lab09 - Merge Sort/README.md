# Lab 09: Merge Sort

This is the first one of the "Divide & Conquer" Algorithms that we'll study in this course and in this the array is divided into two exact equal parts and save them seperately and then plug the values in the right place and then merging them again.

The Dividing is done recursively.
```cpp
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
```

The Merging is done by

```cpp
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
```

The Memory Complexity are
<pre>Best : O(n log(n) )		Average : O(n log(n) )		Worst : O(n log(n) )</pre>

in other words it is a tight bound of `θ(n log(n) )`.

## Tasks

1. Implement Merge Sort
2. Generate an Array of Random Numbers from 1 to 100 with sizes 100, 1000, 10000, 100000, 1000000 and calculate the average case complexity.
3. Calculate the Best & Worst case complexities of the algorithm by passing in a fully sorted list and a reverse sorted list.