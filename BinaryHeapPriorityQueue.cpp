// queue with priority, based on binary heap
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

template<class T>
class Queue {
public:
    Queue(initializer_list<T> l) {
        heapSize = static_cast<int>(l.size());
        reallocateData(heapSize + heapSize/2, l.begin(), l.end());
        buildHeap();
    }
    ~Queue() {
        delete[] data;
    }

    T ExtractMax() {
        cout << "Extracting max element" << endl;
        T maxData = data[0];
        swap(data[0], data[heapSize-1]);
        heapSize--;
        return maxData;
    }

    void Insert(T newValue) {
        cout << "Inserting element: " << newValue << endl;
        reallocateData(heapSize + heapSize/2, data, data + heapSize);
        heapSize++;
        int i = heapSize - 1;
        int p = parent(i);
        while(i > 0 && data[p] < newValue) {
            data[i] = data[p];
            i = p;
            p = parent(p);
        }
        data[i] = newValue;
    }

    void Print() {
        if(heapSize <= 0) {
            cout << "Cannot Print: no data " << endl;
            return;
        }
        int maxHeapHeight = heapHeight();
        cout << "Binary heap with height = " << maxHeapHeight << ":" << endl;
        for(int height = 0; height <= maxHeapHeight; height++){
            int dataCount = pow(2, height);
            int emptyCharCount = pow(2, maxHeapHeight - height);
            int k = dataCount - 1;
            while(k < dataCount - 1 + dataCount && k < heapSize) {
                printEmptyChars(emptyCharCount - 1);
                cout << data[k];
                printEmptyChars(emptyCharCount);
                k++;
            }
            cout << endl;
        }
        cout << endl;
    }


private:
    T* data = nullptr;
    int heapSize = 0;
    int capacity = 0;

    void reallocateData(int newSize, const T* b, const T* e) {
        if(newSize > capacity) {
            T* oldData = data;
            data = new T[newSize];
            copy(b, e, data);
            delete[] oldData;
            capacity = newSize;
        }
    }

    int heapHeight() {return static_cast<int>(log2(heapSize));}

    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int parent(int i) {return i/2-1/4;}

    void heapify(int i) {
        int l = this->left(i);
        int r = this->right(i);
        int largest = i;
        if(l < heapSize && data[l] > data[i]) largest = l;
        if(r < heapSize && data[r] > data[largest]) largest = r;
        if(i != largest) {
            swap(data[i], data[largest]);
            heapify(largest);
        }
    }

    void buildHeap() {
        for(int i = heapSize/2; i >= 0; i--) {
            heapify(i);
        }
    }

    void printEmptyChars(int count) {for(int k = 0; k < count; k++) cout << " ";}

};

int main() {
    Queue<int> q = {1, 2, 3, 4, 5, 8, 3, 2, 6, 5, 3, 4, 1, 5};
    q.Print();
    q.Insert(0);
    q.Print();
    q.Insert(9);
    q.Print();
    int m = q.ExtractMax();
    cout << "  Extracted = " << m << endl;
    q.Print();
}
