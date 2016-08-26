#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;

using namespace std;


inline int partition(vector<int> &array, int left, int right) { // Hoare partitioning
    const int pivot = array[right];
    int l = left;
    int r = right;

    while(true) {
        while(array[l] < pivot) // IMPORTANT: use < instead of <= (othwerwise l may become bigger than arraySize if array[arraySize] is the biggest element
            ++l;
        while(array[r] > pivot) // IMPORTANT: read important above;
            --r;
        if(l < r)
            swap(array[l], array[r]);
        else
            return r;
    }
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
