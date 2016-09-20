#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debug_at(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;
#define debug_pair(p) cout << "> " << #p << " = (" << p.first << ", " << p.second << ")" << endl;

using namespace std;

inline void insertion_sort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 1; i < n; ++i) // arr[0] is already smaller then elements before it
        for(int j = i; j > 0; --j)
            if(arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1])
}

inline void print_arr(const vector<int> &arr) {
    for(int k : arr)
        printf("%d\n", k);
}

int main() {

    int n;
    scanf("%d", &n);
    vector<int> arr(n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    insertion_sort(arr);
    print_arr(arr);

	return 0;
}
