#include <iostream>
#include <vector>
#include <algorithm>		// Used for swap() - Swapping Numbers
#include <iomanip>			// Used for setw() - Alignment

using namespace std;

vector<int> BubbleSort(vector<int> Data);
vector<int> InsertionSort(vector<int> Data);
vector<int> SelectionSort(vector<int> Data);
void PrintVector(vector<int> Data);

int main(int argc, char const *argv[]){
	vector<int> Data;
	// Dummy Data Insertion into Data
	Data.push_back(10);
	Data.push_back(12);
	Data.push_back(425);
	Data.push_back(644);
	Data.push_back(41);
	Data.push_back(0);
	Data.push_back(12);

	// Printing the Original Array
	cout << "Original Array :\t";
	PrintVector(Data);

	// Bubble Sorting
	// Returns a vector which then updates the original vector
	Data = BubbleSort(Data);
	cout << endl << "Bubble Sort :\t\t";
	PrintVector(Data);

	// Insertion Sorting
	// Returns a vector which then updates the original vector
	Data = InsertionSort(Data);
	cout << endl << "Insertion Sort :\t";
	PrintVector(Data);
	
	// Selection Sort
	// Returns a vector which then updates the original vector
	Data = SelectionSort(Data);
	cout << endl << "Selection Sort :\t";
	PrintVector(Data);

	return 0;
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

void PrintVector(vector<int> Data){
	for (int i = 0; i < Data.size(); ++i){
		cout << setw(3) << Data[i] << " ";
	}
}