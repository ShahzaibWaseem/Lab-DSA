#include <iostream>
#include <vector>

using namespace std;

int main (){
	int size, maxSize = 100, sum = 0;
	do{
		// Getting input Array
		cout << "What are the sizes of the Arrays : ";
		cin >> size;
	}while(size > maxSize);					// Size Check

	// Arrays & Vector Defination
	int array[size], countArray[maxSize], cumulativeDistribution[maxSize];
	vector <string> strArray (size), sorted (size);

	// countArray equals to 0
	for (int i = 0; i < maxSize; ++i){
		countArray[i] = 0;
		cumulativeDistribution[i] = 0;
	}

	cout << endl << "Enter Numbers & Strings"<< endl;
	for(int i = 0; i < size; i++){
		cin >> array[i] >> strArray[i];
		sorted[i] = "-";					// Making the whole sorted array into dashes
											// will update this array later
        countArray[array[i]]++;
	}

	// Printing the original array
	cout << endl << "Original Array (Number) : ";
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";

	// Printing the original strArray
	cout << endl << "Original Array (Strings) : ";
	for (int i = 0; i < size; ++i)
		cout << strArray[i] << " ";

	// Printing the count Array
	cout << endl << endl << "Count Array" << endl;
    for (int i = 0; i < maxSize; ++i)
    	cout << countArray[i] << " ";

    // saving the cumulativeDistribution in an array
    for (int i = 0; i < maxSize; i++){
    	sum += countArray[i];
    	cumulativeDistribution[i] = sum; 
    }

    // Printing the count Array
	cout << endl << endl << "Cumulative Distribution Array" << endl;
    for (int i = 0; i < maxSize; ++i)
    	cout << cumulativeDistribution[i] << " ";

    // Applying the TWIST Part
    for (int i = 0; i < size; i++){
    	int tempPosition = cumulativeDistribution[array[i]] - countArray[array[i]];
    	if(i >= (size / 2))
    		sorted[tempPosition] = strArray[i];
    	cumulativeDistribution[array[i]]++;
    }

	// Printing the sorted Array with the Twist
	cout << endl << endl << "Sorted Array" << endl;
	for (int i = 0; i < size; ++i)
		cout << sorted[i] << " ";

	return 0;
}