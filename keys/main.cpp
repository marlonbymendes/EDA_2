#include <bits/stdc++.h>
#include "grid.h"
#include "bfs.h"

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debug_at(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;
#define debug_pair(p) cout << "> " << #p << " = (" << p.first << ", " << p.second << ")" << endl;

using namespace std;

// Read lines until EOF
inline vector<string> read_grid();

int main() {

    vector<string> lines = read_grid();
    Grid grid(lines);
    int ans = shortest_distance_start_goal(grid);
    debug(ans);


	return 0;
}

inline vector<string> read_grid() {
    string line;
    vector<string> lines;
    while(cin >> line) {
        lines.push_back(line);
    }
    return lines;
}
