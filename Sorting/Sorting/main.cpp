#include <iostream>
#include <utility>
#include <vector>
#include "sort.h"
#include <cstdlib>
#include <ctime>

template <typename T>
void Print(T data[], size_t size) {
	for (size_t i = 0; i < size; ++i)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void generate(T data[], size_t size) {
	for (size_t i = 0; i < size; ++i)
		data[i] = std::rand() % 100;
}

int main() {
	std::srand(time(0));
	const int size = 10;
	{
		std::cout << "Insertion sort:" << std::endl;
		int data[size];
		generate(data, size);
		Print(&data[0], size);
		InsertionSort(&data[0], size);
		Print(&data[0], size);
	}

	{
		std::cout << "Selection sort:" << std::endl;
		int data[size];
		generate(data, size);
		Print(&data[0], size);
		SelectionSort(&data[0], size);
		Print(&data[0], size);
	}

	{
		std::cout << "Merge sort:" << std::endl;
		int data[size];
		generate(data, size);
		Print(&data[0], size);
		MergeSort(&data[0], 0, size -1);
		Print(&data[0], size);
	}
	{
		std::cout << "Quick sort:" << std::endl;
		int data[size];
		generate(data, size);
		Print(&data[0], size);
		QuickSort(&data[0], 0, size -1);
		Print(&data[0], size);
	}
	system("pause");
	return 0;
}
