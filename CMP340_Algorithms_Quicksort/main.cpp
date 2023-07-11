#include <iostream>
using namespace std;


/*note: We increased the memory allocation to the stack by
increasing the stack reserve and commit sizes for the project file in order to
accommodate the large arrays of size n = 105
.*/


int main() {
	srand(time(NULL) + rand());
	long count = 0;
	int size = 100000;
	int start = 0;
	int end = 99999;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 30000;
	}
	cout << "\nBefore Quicksort:\n";
	printArray(array, size);
	quicksort(array, start, end, count);
	cout << "\nAfter Quicksort:\n";
	printArray(array, size);
	cout << "The total number of comparison operations are: " << count << endl;
	delete[] array;
	return 0;
}

/* note: The srand() is used to change the seed each time, and get different results per
run.
Also, the RAND_MAX = 32767 is quite weird to me, I modded it with 30,000 which
doesn’t make any difference, but I would have liked to test the function with an unsorted
array of unique elements. :( */