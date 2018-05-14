#include <iostream>
#include <utility>
#include <vector>

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

template <typename T>
void MergeSort(T data[], size_t left, size_t right) {
	const size_t len = right - left + 1;
	if (len < 2)
		return;
	size_t mid = left + len / 2 - 1;
	MergeSort(&data[0], left, mid);
	MergeSort(&data[0], mid + 1, right);
	size_t current_left = left;
	size_t current_right = mid + 1;
	size_t i = 0;
	std::vector<T> buf;
	while (i < len) {
		if (current_right > right || data[current_left] <= data[current_right] && current_left <= mid) {
			buf.push_back(data[current_left]);
			++current_left;
		} else if (current_left > mid || data[current_right] <= data[current_left] && current_right <= right) {
			buf.push_back(data[current_right]);
			++current_right;
		}
		++i;
	}
	for (size_t i = 0; i < len; ++i) {
		data[i + left] = buf[i];
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

	{
		std::cout << "Merge sort:" << std::endl;
		int data[] = { 5, 4, 3, 1, 2, 10 };
		auto len = sizeof(data) / sizeof(data[0]);
		Print(&data[0], len);
		MergeSort(&data[0], 0, len-1);
		Print(&data[0], len);
	}
	system("pause");
	return 0;
}