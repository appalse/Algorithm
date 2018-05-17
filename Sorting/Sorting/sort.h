#pragma once

template <typename T>
void InsertionSort(T data[], size_t len) {
	for (size_t i = 1; i < len; ++i)
		for (int j = i; j > 0; --j)
			if (data[j] < data[j - 1])
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
	int mid = (left + right) / 2;
	MergeSort(data, left, mid);
	MergeSort(data, mid + 1, right);
	const int buffLength = right - left + 1;
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

template <typename T>
void QuickSort(T data[], int left, int right) {
	if (right < left)
		return;
	int mid = data[(left + right) / 2];
	int currentLeft = left;
	int currentRight = right;
	while (currentLeft <= currentRight) {
		while (data[currentLeft] < mid) ++currentLeft;
		while (data[currentRight] > mid) --currentRight;
		if (currentLeft <= currentRight) {
			std::swap(data[currentLeft], data[currentRight]);
			++currentLeft;
			--currentRight;
		}
	}
	QuickSort(data, left, currentRight);
	QuickSort(data, currentLeft, right);
}
