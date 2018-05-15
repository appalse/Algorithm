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
void MergeSort(T data[], int left, int right) {
    if (right == left)
        return;
    int mid = (left + right)/2;
    MergeSort(data, left, mid);
    MergeSort(data, mid + 1, right);
    const int buffLength = right - left+ 1;
    std::vector<T> buff(buffLength);
    int currentLeft = left;
    int currentRight = mid + 1;
    for (int step = 0; step < buffLength; ++step) {
        if (data[currentLeft] < data[currentRight] && currentLeft <= mid || currentRight > right) {
            buff[step] = data[currentLeft];
            ++currentLeft;
        } else {
            buff[step] = data[currentRight];
            ++currentRight;
        }
    }

    for (int step = 0; step < buffLength; ++step) {
        data[left + step] = buff[step];
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
