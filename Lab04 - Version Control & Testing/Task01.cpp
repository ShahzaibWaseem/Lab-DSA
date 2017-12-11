#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	// to get a random value (argument is called seed)
	srand(time(NULL));
	int randomNumber;
	char moreRandom;
	cout << "Here are 10 random Numbers generated from 1 - 6" << endl;
	do{
		for (int i = 0; i < 10; i++){
			/* generate secret number between 1 and 6: */
			randomNumber = rand() % 6 + 1;
			cout << randomNumber << " ";
		}
		cout << endl << "Do you want any more random Numbers (Enter any character) [Loop Terminator: 'n'/'N'] ??? ";
		cin >> moreRandom;
	} while (moreRandom != 'n' && moreRandom != 'N');

	cout << endl;
	system("PAUSE");	// to pause output stream
	return 0;
}