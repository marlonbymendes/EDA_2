#include <utility>
#include <vector>
#include <string>

using namespace std;

#ifndef GRID_H
#define GRID_H

typedef pair<int, int> Cell; // Position (x, y) in grid

class Grid {
private:

    int rows; // Number of lines in grid;
    int cols; // Number of columns in grid

    vector<string> lines;

    void set_rows();
    void set_cols();
    void set_start_goal();

    const char START = '@';
    const char GOAL = '*';
    const char BLOCKED = '#';

public:

    Cell start;
    Cell goal;

    Grid(const vector<string>& lines);

    void print_grid();
    void print_cell(const string& name, const Cell& cell);
    void print_start();
    void print_goal();

    int get_rows() const;
    int get_cols() const;
    char get_cell(const int x, const int y) const;

    bool valid(const int x, const int y) const;
    bool is_key(const int x, const int y) const;
    bool is_locked(const int x, const int y) const;
};

#endif

#ifndef NODE_H
#define NODE_H

class Node {
private:

    int to_int(const char key) const;

public:
    Cell pos;

    /* Bitmask containing keys
     * contains i'th key if and only if  i'th bit (1 << i) is set (1) */
    int keys; // Bitmask representing keys;

    Node(const Cell& pos, const int keys);

    void add_key(const char key);
    bool have_key(const char key) const;
};

#endif
