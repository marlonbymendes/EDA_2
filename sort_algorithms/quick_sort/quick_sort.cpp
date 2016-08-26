#include <bits/stdc++.h>

using namespace std;

inline int partition(vector<int> &array, int left, int right) { // Lomuto partitioning
    const int pivot = array[right];
    int first_bigger = left;    // index of the first element in the current interval of all elements bigger than the pivot

    for(int i = left; i < right; ++i) {
        if(array[i] <= pivot) {
            swap(array[i], array[first_bigger]);
            first_bigger++;
        }
    }
    swap(array[right], array[first_bigger]);
    return first_bigger;
}

inline void quick_sort(vector<int> &array, int left, int right) {
    if(left < right) {
        int pivot_position = partition(array, left, right);
        quick_sort(array, left, pivot_position - 1);
        quick_sort(array, pivot_position + 1, right);
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

    int left = 1, right = arraySize;
    quick_sort(array, left, right);

    printArray(array, arraySize);

	return 0;
}
