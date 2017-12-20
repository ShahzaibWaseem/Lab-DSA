# Lab 07: Bubble, Selection & Insertion Sort

The snippets of all three Sorting Algorithms are given below (with Time Complexities).

#### Bubble Sort
<pre>Best : O(n<sup>2</sup>)		Average : O(n<sup>2</sup>)			Worst : O(n<sup>2</sup>)</pre>
```cpp
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
```

#### Selection Sort
<pre>Best : O(n)		Average : O(n<sup>2</sup>)			Worst : O(n<sup>2</sup>)</pre>
```cpp
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
```

#### Insertion Sort
<pre>Best : O(n)		Average : O(n<sup>2</sup>)			Worst : O(n<sup>2</sup>)</pre>
```cpp
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
```


## Tasks

1. Implement Bubble, Selection & Insertion Sort.
2. Generate arrays of random number from 1 to 100 with sizes 100, 1000, 10000, 100000, 1000000 and compare the running times of the algortihms.
3. Calculate the Best & Worst case complexities of the algorithms by passing in a fully sorted list and a reverse sorted list and comparing them.

## Comparison among Bubble, Selection & Insertion Sort

Bubble Sort is the Slowest Sorting Algorithm of the bunch. It loops through the whole array of size n, n times. Selection Sort is faster than Bubble Sort as it does not loop through the elements which are unnecessary. Insertion Sort is Fastest of all three for random array, but it has an exception that it does not do very well for reverse Sorted Array. As it can be seen in the [Visualization](https://www.visualgo.net/bn/sorting).

This [Website](https://www.titrias.com/ultimate-sorting-algorithms-comparison/) Compares Bubble, Selection, Insertion Sort to the more powerful and fast Algorithms like [Merge Sort](https://github.com/Shahzaib-FCB/Lab-DSA/tree/master/Lab09%20-%20Merge%20Sort) and [Quick Sort](https://github.com/Shahzaib-FCB/Lab-DSA/tree/master/Lab10%20-%20Quick%20Sort) which both have `O(n(logn))`.