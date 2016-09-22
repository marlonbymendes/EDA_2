#include <bits/stdc++.h>

#define debug(x) cout << ">> " << #x << " = " << x << endl
#define debug_at(arr, at) cout << ">> " << #arr << "[" << at << "] = " << arr[at] << endl

using namespace std;

const int INF = 1 << 30;

class Heap {
private:

//    const int INF = 1 << 30;

    int heapSize;
    vector<int> heap;

    inline void buildMaxHeap() {
        for(int i = heapSize / 2; i >= 1; --i) {
            maxHeapify(i);
        }
    }

    void maxHeapify(int i) { // 1 indexed
        int maxIndex = i;
        int leftIndex = left(i);
        int rightIndex = right(i);

        if(leftIndex <= heapSize and heap[leftIndex] > heap[i])
            maxIndex = leftIndex;
        if(rightIndex <= heapSize and heap[rightIndex] > heap[maxIndex])
            maxIndex = rightIndex;
        if(maxIndex != i) {
            swap(heap[i], heap[maxIndex]);
            maxHeapify(maxIndex);
        }
    }

    inline int left(int i) {
        return 2 * i;
    }

    inline int right(int i) {
        return left(i) + 1;
    }

    inline int parent(int i) {
        assert(i > 1);
        return i / 2;
    } 
public:
    Heap() {
        heapSize = 0;
        heap = vector<int>();
    }

    Heap(vector<int> &array, int arraySize) {
        heap = array;
        heapSize = arraySize;
        buildMaxHeap();
    }
    
   inline int pop() {
        assert(heapSize > 0);
        int maxElement = heap[1];
        swap(heap[1], heap[heapSize]);
        --heapSize;
        maxHeapify(1);
        return maxElement;
    }

    inline void modify(int i, int value) {
        assert(value > heap[i]);
        heap[i] = value;
        while(i > 1 and heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    inline void push(int element) {
        ++heapSize;
        heap.push_back(-INF);
        modify(heapSize, element);
    }

    inline void print() {
        debug(heapSize);
        cout << "\n>>\n";
        for(int i = 1; i <= heapSize; ++i) {
            debug_at(heap, i);
        }
        cout << ">>\n\n";
    }
};

inline void heapSort(vector<int> &array, int arraySize) {
    Heap heap(array, arraySize);
    for(int i = arraySize; i >= 1; --i) {
        array[i] = heap.pop();
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
