#include <iostream>
using namespace std;

int main() {
	srand(time(NULL) + rand());
	long count = 0;
	int size = 100000;
	int start = 0;
	int end = 99999;
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = i + 1;
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

/* note: It is basically the same code as main, just generating a sorted array instead (from 1 to
the size). */
