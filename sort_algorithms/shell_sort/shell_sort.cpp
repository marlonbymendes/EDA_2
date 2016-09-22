#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debug_at(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;
#define debug_pair(p) cout << "> " << #p << " = (" << p.first << ", " << p.second << ")" << endl;

using namespace std;

inline void shell_sort(vector<int> &arr) {
    int n = arr.size();

    int gap = n / 2;
    while(gap > 0) {
        for(int i = gap; i < n; ++i) {
            int nextElement = arr[i];
            int j = i;
            while(j >= gap and arr[j - gap] > nextElement) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = nextElement;
        }
        gap /= 2;
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

    shell_sort(arr);
    print_arr(arr);

	return 0;
}
