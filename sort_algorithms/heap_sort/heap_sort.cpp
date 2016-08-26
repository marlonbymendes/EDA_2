#include <bits/stdc++.h>

using namespace std;

inline int left(int i) {
    return 2 * i;
}

inline int right(int i) {
    return left(i) + 1;
}

void maxHeapify(int i, vector<int> &array, int heapSize) { // 1 indexed
    int maxIndex = i;
    int leftIndex = left(i);
    int rightIndex = right(i);

    if(leftIndex <= heapSize and array[leftIndex] > array[i])
        maxIndex = leftIndex;
    if(rightIndex <= heapSize and array[rightIndex] > array[maxIndex])
        maxIndex = rightIndex;
    if(maxIndex != i) {
        swap(array[i], array[maxIndex]);
        maxHeapify(maxIndex, array, heapSize);
    }
}

inline void buildMaxHeap(vector<int> &array, int arraySize) {
    int heapSize = arraySize;
    for(int i = arraySize / 2; i >= 1; --i) {
        maxHeapify(i, array, heapSize);
    }
}

inline void heapSort(vector<int> &array, int arraySize) {
    buildMaxHeap(array, arraySize);
    int heapSize = arraySize;

    for(int i = arraySize; i >= 2; --i) {
        swap(array[i], array[1]);
        --heapSize;
        maxHeapify(1, array, heapSize);
    }
}

inline void printArray(const vector<int> &array, int arraySize) {
    for(int i = 1; i <= arraySize; ++i) {
        cout << array[i] << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    int arraySize;
    cin >> arraySize;

    vector<int> array(arraySize + 1);
    for(int i = 1; i <= arraySize; ++i) {
        cin >> array[i];
    }

    heapSort(array, arraySize);
    printArray(array, arraySize);

	return 0;
}
