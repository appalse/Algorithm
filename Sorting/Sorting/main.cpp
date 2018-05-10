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



int main() {
	int data[] = {5, 4, 3, 1, 2, 10};
	auto len = sizeof(data) / sizeof(data[0]);
	Print(&data[0], len);
	InsertionSort(&data[0], len);
	Print(&data[0], len);
	system("pause");
	return 0;
}