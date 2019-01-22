// Binary heap sorting procedure
// n logn
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Left(int i) {
    return i*2;
}

int Right(int i) {
    return i*2 + 1;
}

template<typename T>
void Heapify(T& A, int len, int i){
    cout << "Heapify len=" << len << ", i=" << i << endl;
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if(l < len && A[l] > A[i]) largest = l;
    if(r < len && A[r] > A[largest]) largest = r;
    if(largest != i) {
        swap(A[i], A[largest]);
        Heapify<T>(A, len, largest);
    }
}

template<typename T>
void BuildHeap(T& A, int len){
    for(int i = len/2; i >= 0; i--) {
        cout << "BuildHeap #" << i << endl;
        Heapify(A, len, i);
    }
}

template<typename T>
void HeapSort(T& A, int len) {
    BuildHeap(A, len);
    int heapSize = len;
    for(int i = len-1; i > 0; i--) {
        swap(A[i], A[0]);
        heapSize--;
        Heapify(A, heapSize, 0);
    }
}

template<typename T>
void Print(T& A) {
    cout << "  Sorted array: ";
    for(auto& i: A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    HeapSort(v, static_cast<int>(v.size()));
    Print(v);

    vector<char> c = {'w', 'q', 'r', 's', 'a', 'g'};
    HeapSort(c, static_cast<int>(c.size()));
    Print(c);
}
