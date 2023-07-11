#include <iostream>
using namespace std;

int partitionQ1(int a[], int left, int right, long& count)
{
	int pivot = a[left];
	int s = left;
	for (int i = left + 1; i <= right; i++) {
		if (a[i] < pivot) {
			s = s + 1;
			//swap(a[s], a[i]);
		}
		count++;
	}
	swap(a[s], a[left]);
	int i = left;
	int j = right;
	while (i<s and j>s) {
		while (a[i] <= pivot) i++;
		while (a[j] > pivot) j--;
		if (i<s and j>s) {
			swap(a[i++], a[j--]);
		}
		count++;
	}
	return s;
}
void quicksort(int a[], int left, int right, long& count)
{
	if (left < right) {
		int s = partitionQ1(a, left, right, count);
		quicksort(a, left, s - 1, count);
		quicksort(a, s + 1, right, count);
	}
}
void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << a[i] << "\t";
		if (i % 14 == 13) cout << endl;
	}
	cout << endl << endl;
}