#ifndef SORTINGS_H
#define SORTINGS_H

namespace srt {

	template<typename T>
	bool is_sorted(T* arr, size_t size);

	template<typename T>
	void swap(T& a, T& b);

	// Simple sort
	template<typename T>
	void simple_sort(T* arr, size_t size);

	// Selection sort
	template<typename T>
	void selection_sort(T* arr, size_t size);

	// Insertion sort
	template<typename T>
	void insertion_sort(T* arr, size_t size);

	// Bubble sort
	template<typename T>
	void bubble_sort(T* arr, size_t size);

	// Merge sort
	template<typename T>
	void merge(T* arr, size_t left, size_t middle, size_t right);
	template<typename T>
	void merge_sort(T* arr, size_t left, size_t right);
	template<typename T>
	void merge_sort(T* arr, size_t size);

	// Quick sort
	template<typename T>
	int partition(T* arr, int low, int high);
	template<typename T>
	void quick_sort(T* arr, int low, int high);
	template<typename T>
	void quick_sort(T* arr, int size);

}



template<typename T>
bool srt::is_sorted(T* arr, size_t size) {
	bool flag = true;
	for (size_t i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			flag = false;
			break;
		}
	}
	return flag;
}

template<typename T>
void srt::swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

// Simple sort
template<typename T>
void srt::simple_sort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				srt::swap(arr[i], arr[j]);
			}
		}
	}
}

// Selection sort
template<typename T>
void srt::selection_sort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		size_t min_index = i;
		for (size_t j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		srt::swap(arr[i], arr[min_index]);
	}
}

// Insertion sort
template<typename T>
void srt::insertion_sort(T* arr, size_t size) {
	for (size_t i = 1; i < size; i++) {
		T key = arr[i];
		size_t j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

// Bubble sort
template<typename T>
void srt::bubble_sort(T* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				srt::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Merge sort
template<typename T>
void srt::merge(T* arr, size_t left, size_t middle, size_t right) {
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	T* L = new T[n1];
	T* R = new T[n2];

	for (size_t i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (size_t i = 0; i < n2; i++)
		R[i] = arr[middle + 1 + i];

	size_t i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];

	delete L;
	delete R;
}
template<typename T>
void srt::merge_sort(T* arr, size_t left, size_t right) {
	if (left < right) {
		size_t middle = left + (right - left) / 2;
		srt::merge_sort(arr, left, middle);
		srt::merge_sort(arr, middle + 1, right);
		srt::merge(arr, left, middle, right);
	}
}
template<typename T>
void srt::merge_sort(T* arr, size_t size) {
	srt::merge_sort(arr, 0, size - 1);
}

// Quick sort
template<typename T>
int srt::partition(T* list, int start, int pivot)
{
	int i = start;
	while (i < pivot)
	{
		if (list[i] > list[pivot] && i == pivot - 1)
		{
			srt::swap(list[i], list[pivot]);
			pivot--;
		}

		else if (list[i] > list[pivot])
		{
			srt::swap(list[pivot - 1], list[pivot]);
			srt::swap(list[i], list[pivot]);
			pivot--;
		}

		else i++;
	}
	return pivot;
}
template<typename T>
void srt::quick_sort(T* list, int start, int end)
{
	if (start < end)
	{
		int pivot = srt::partition(list, start, end);

		srt::quick_sort(list, start, pivot - 1);
		srt::quick_sort(list, pivot + 1, end);
	}
}
template<typename T>
void srt::quick_sort(T* arr, int size) {
	srt::quick_sort(arr, 0, size - 1);
}

/*
template<typename T>
size_t srt::partition(T* arr, size_t low, size_t high) {
	T pivot = arr[high];
	int i = (low - 1);

	for (size_t j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			srt::swap(arr[i], arr[j]);
		}
	}

	srt::swap(arr[i + 1], arr[high]);
	return (i + 1);
}
template<typename T>
void srt::quick_sort(T* arr, size_t low, size_t high) {
	if (low < high) {
		size_t pivot_index = srt::partition(arr, low, high);
		srt::quick_sort(arr, low, pivot_index - 1);
		srt::quick_sort(arr, pivot_index + 1, high);
	}
}
template<typename T>
void srt::quick_sort(T* arr, size_t size) {
	srt::quick_sort(arr, 0, size - 1);
}
*/


#endif // !SORTINGS_H
