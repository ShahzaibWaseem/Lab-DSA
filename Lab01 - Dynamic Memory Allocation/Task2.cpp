/*
* Name: M. Shahzaib Waseem
* Student #: 187330
*/

#include <iostream>

using namespace std;

/*
* PROBLEM #2: Analyze pointers
*/

/*
* PART #1: Write a function that does two things:
* >> Write the memory location pointed by the pointer to the console.
* >> Write the value of the integer (which the pointer points to) to the console.
*/
void analyze_pointer(int *ptr)
{
	cout << "Value : " << *ptr << endl;
	cout << "Address : " << ptr << endl;
}


/*
* PROBLEM #3: Add a couple more functions to the mix
* >> call them int_pointer1 and int_pointer2
* >> both will return int pointers.
*/

/*
* Follow the steps:
* >> the function will allocate an int on the heap (via new int)
* >> assign a value to it
* >> and return that value (an int pointer type).
*/


int* int_pointer1()
{
	int* intP1 = new int;
	*intP1 = 30;

	//delete intP1;
	return intP1;
}
/*
* Follow the steps:
* >> the function will allocate an int on the stack (via "int iValue;" or something similar)
* >> assign a value to it
* >> and return its memory location (an int pointer type).
*/
int* int_pointer2()
{
	int intVal2 = 40;
	return &intVal2;
}

int main()
{
	/*
	* PART #2: Use the analyze_pointer function to complete two TASKS
	*/

	/*
	* TASK #1
	* >> allocate an int on the stack (e.g.,  "int iValue;")
	* >> assign a value to it
	* >> get its memory location (with the reference operator---&)
	* >> and pass this value to analyze_pointer.
	*/
	int iValue = 10;

	cout << "Part #2: Memory on stack..." << endl;
	analyze_pointer(&iValue);

	/*
	* TASK #2
	* >> allocate an int on the heap (with the new operator)
	* >> assign a value to it
	* >> and pass it to analyze_pointer.
	*/
	int* pValue = new int;
	*pValue = 20;

	cout << "Memory on heap..." << endl;
	analyze_pointer(pValue);

	/*
	* PROBLEM #3: Call analyze_pointer on the return of functions int_pointer1() and int_pointer2()
	*/
	cout << endl << "Part #3: Memory on heap versus on stack..." << endl;
	cout << "HEAP" << endl;
	analyze_pointer(int_pointer1());
	cout << "STACK" << endl;
	analyze_pointer(int_pointer2());

	/*
	* Remember that int was allocated on the heap for function "int_pointer1()"
	* Delete it
	* and call analyze_pointer on it after deleting it.
	*/
	cout << "Memory on heap after delete..." << endl;

	analyze_pointer(new int);

	system("pause");
	return 0;
}