# Lab 1 : Pointers & Dynamic Memory

## Tasks

### Task 1

Rewrite this program using pointers in place of arrays.

```cpp
include<iostream>
using namespace std;

int main(void){
	int salary[20];
	int i;
	for (i=0;i<20;++i){
		cout <<"Enter Salary: ";
		cin >>salary[i];
	}
	for (i=0;i<20;++i)
		salary[i]=salary[i]+salary[i]/(i+1);
	return 0;
}
```

### Task 2

#### Part 1:

Write a function void analyze_pointer `(int *ptr)` that does two things:
* Write the memory location pointed by the pointer to the console.
* Write the value of the integer (which the pointer points to) to the console.

#### Part 2:
Use the function to complete two tasks:
* Allocate an int on the stack (e.g., `int iValue;`), assign a value to it, and get its memory location (with the reference operator `&`) to pass this value to `analyze_pointer()`.
* Allocate an int on the heap (with the new operator). Assign a value to it, and pass it to `analyze_pointer()`.

##### Question #1. What happens?

#### Part 3:

Now, we're going to add a couple more functions to the mix; call them `int_pointer1()` and `int_pointer2()`. Both will return int pointers.

* `int_pointer1` will allocate an int on the heap (via new int), assign a value to it, and return that value.
* `int_pointer2` will allocate an int on the stack (via `int iValue;` or something similar), assign a value to it, and return its memory location (as both of these functions should be of the int pointer type).

Call analyze_pointer on the return of both of these functions from your main function:
* `analyze_pointer( int_pointer1() );`
* `analyze_pointer( int_pointer2() );`

##### Question #2. What happens, and why?

Two more tests on Memory:

* Remember that int we allocated on the heap for function `int_pointer1()`. Delete it, and call analyze_pointer on it after deleting it.
* Call: analyze_pointer(new int);

##### Question #3. After completion of the problem, how many memory leaks are there?

### Task 3
Define a `class Area` that has two private variable members; `units` of type string and `area_value` of type float. Modify the Lab_1_-_Problem_3.cpp program to create a dynamic variable (object) of type Area.
* Input from the keyboard the `area_value` and its `units`. Compute one-half and one-quarter of the area and display the results.
* `Destroy` the dynamic variable at the end.