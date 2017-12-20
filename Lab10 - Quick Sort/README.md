# Lab 10: Quick Sort

In this Sorting Algorithm the original array needs to be partitioned and the reconstructed but keeping in mind not to use any extra space while partitioning it as we did in the [Merge Sort](https://github.com/Shahzaib-FCB/Lab-DSA/tree/master/Lab09%20-%20Merge%20Sort).

### Partition

```cpp
int Partition(int* Data, int first, int second){
	int pivot, i, j;
	pivot = Data[first];
	i = first;			// i is the starting location of first partition
	j = second + 1;			// j is the starting location of second partition

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
```

And here is the code to reconstruct the Sorted Array
```cpp
void QuickSort(int* Data, int head, int tail){
	if (head < tail){
		int temp = Partition(Data, head, tail);
		// Recursion with first half of partition
		QuickSort(Data, head, temp - 1);
		// Recursion with second half of partition
		QuickSort(Data, temp + 1, tail);
	}
}
```

The Memory Complexities are
<pre>Best : O(n log(n) )		Average : O(n log(n) )		Worst : O(n<sup>2</sup>)</pre>

## Tasks

1. Run Quick Sort on arrays of random numbers in range 1 to 100 with sizes 100, 1000, 10000.
2. Compare the number of partition in each case.
3. Choose a different pivot value to see the pattern in number of partitions.