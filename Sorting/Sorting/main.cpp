#include <iostream>
#include <utility>

template <typename T>
void Print(T data[], size_t len) {
	for (size_t i = 0; i < len; ++i)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void InsertionSort(T data[], size_t len) {
	for (size_t i = 1; i < len; ++i) 
		for (int j = i; j > 0; --j) 
			if (data[j] < data[j-1]) 
				std::swap(data[j], data[j - 1]);
}

template <typename T>
void SelectionSort(T data[], size_t len) {
	for (size_t i = 0; i < len - 1; ++i) {
		T minItem = data[i];
		size_t minIndex = i;
		for (size_t j = i + 1; j < len; ++j)
			if (data[j] < minItem) {
				minItem = data[j];
				minIndex = j;
			}
		if (minIndex != i)
			std::swap(data[i], data[minIndex]);
	}
}



int main() {
	{
		std::cout << "Insertion sort:" << std::endl;
		int data[] = { 5, 4, 3, 1, 2, 10 };
		auto len = sizeof(data) / sizeof(data[0]);
		Print(&data[0], len);
		InsertionSort(&data[0], len);
		Print(&data[0], len);
	}

	{
		std::cout << "Selection sort:" << std::endl;
		int data[] = { 5, 4, 3, 1, 2, 10 };
		auto len = sizeof(data) / sizeof(data[0]);
		Print(&data[0], len);
		SelectionSort(&data[0], len);
		Print(&data[0], len);
	}
	system("pause");
	return 0;
}