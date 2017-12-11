#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main (){
	srand(time(NULL));

	int size, maxSize = 100, random = 0;
	do{
		// Getting input Array
		cout << "What is the size of the Array : ";
		cin >> size;
	}while(size > maxSize);					// Size Check

	// Arrays Defination
	int array[size], countArray[maxSize];

	// countArray equals to 0
	for (int i = 0; i < maxSize; ++i)
		countArray[i] = 0;

	for(int i = 0; i < size; i++){
		random = rand() % 100 + 1;			// Getting random numbers
        array[i] = random;
        countArray[array[i]]++;
	}

	// Printing the original Array
	cout << endl << "Original Array : ";
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";

	// Printing the count Array
	cout << endl << endl << "Count Array" << endl;
    for (int i = 0; i < maxSize; ++i)
    	cout << countArray[i] << " ";

	// Printing the sorted Array
	cout << endl << endl << "Sorted Array" << endl;
    for (int i = 0; i < maxSize; ++i){
    	while(countArray[i] > 0){
    		countArray[i]--;
    		cout << i << " ";
    	}
    }

	return 0;
}