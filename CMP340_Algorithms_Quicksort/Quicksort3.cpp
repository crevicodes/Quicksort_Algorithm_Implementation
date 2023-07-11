#include <iostream>
using namespace std;

int indexOfMedian(int arr[], int left, int right) {
	int size = (right - left) + 1;
	int x = (rand() % size) + left, y = (rand() % size) + left, z = (rand() % size) + left;
	if (size >= 3) {
		while (y == x) y = (rand() % size) + left;
		while (z == x or z == y) z = (rand() % size) + left;
	}
	int a = arr[x], b = arr[y], c = arr[z];
	if ((a <= b and b <= c) or (c <= b and b <= a))
		return y;
	else if ((b <= a and a <= c) or (c <= a and a <= b))
		return x;
	else
		return z;
}
int partitionQ3(int a[], int left, int right, long& count)
{
	int median = indexOfMedian(a, left, right);
	swap(a[left], a[median]);
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
		if (i<s and j>s) swap(a[i++], a[j--]);
		count++;
	}
	return s;
}
void quicksort(int a[], int left, int right, long& count)
{
	if (left < right) {
		int s = partitionQ3(a, left, right, count);
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
