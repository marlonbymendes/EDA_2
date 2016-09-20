#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debug_at(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;
#define debug_pair(p) cout << "> " << #p << " = (" << p.first << ", " << p.second << ")" << endl;

using namespace std;

inline void selection_sort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i < n; ++i) {
        int min_index = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
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

    selection_sort(arr);
    print_arr(arr);

	return 0;
}
