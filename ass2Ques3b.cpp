#include <iostream>
using namespace std;

int main() {
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int arr[size];
	cout << "Enter elements of the array:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int start = 0, end = size - 1;
	int missing = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == mid + 1) {
			start = mid + 1;
		}
		else {
			missing = mid + 1;
			end = mid - 1;
		}
	}

	cout << "Missing number is: " << missing << endl;
	return 0;
}
