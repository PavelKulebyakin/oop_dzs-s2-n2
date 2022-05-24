#include "switch_func.h"

int main() {

	srand(time(0));

	unsigned arr_len = abs(random(10)) + 5;

	int* arr = new int[arr_len];

	for (int i = 0; i < arr_len; i++) {
		arr[i] = random(100);
	}

	std::cout << "Old array:\t";

	for (int i = 0; i < arr_len; i++) {
		std::cout << arr[i] << "\t";
	}

	void (*func)(int*, unsigned) = switch_func(arr, arr_len);

	func(arr, arr_len);

	std::cout << "\n\nNew array:\t";

	for (int i = 0; i < arr_len; i++) {
		std::cout << arr[i] << "\t";
	}

	std::cout << "\n";


}
