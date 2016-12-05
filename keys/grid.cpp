#include<vector>
#include<cassert>
#include<cctype>
#include<iostream>
#include<string>

#include "grid.h"

using namespace std;

void Grid::set_rows() {
    assert(not lines.empty());
    rows = this->lines.size();
}

void Grid::set_cols() {
    assert(not lines.empty());
    assert(not lines[0].empty());
    cols = this->lines[0].size();
}

void Grid::set_start_goal() {
    for(int i = 0; i < this->rows; ++i) {
        for(int j = 0; j < this->cols; ++j) {
            if(lines[i][j] == START) {
                this->start = Cell(i, j);
            }
            else if(lines[i][j] == GOAL) {
                this->goal = Cell(i, j);
            }
        }
    }
}

void Grid::print_grid() {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << lines[i][j];
        }
        cout << endl;
    }
}

Grid::Grid(const vector<string>& _lines) : lines(_lines) {
    set_rows();
    set_cols();
    set_start_goal();
}

void Grid::print_cell(const string& name, const Cell& cell) {
    cout << name << " = (" << cell.first << ", " << cell.second << ")" << endl;
}

void Grid::print_start() {
    print_cell("START", start);
}

void Grid::print_goal() {
    print_cell("GOAL", goal);
}

int Grid::get_rows() const {
    return this->rows;
}

int Grid::get_cols() const {
    return this->cols;
}

bool Grid::valid(const int x, const int y) const {
    // inside grid
	if((x >= 0 and x < rows) and (y >= 0 and y < cols))
		return lines[x][y] != BLOCKED;
    // outside grid
    return false;
}

char Grid::get_cell(const int x, const int y) const {
    return this->lines[x][y];
}

bool Grid::is_key(const int x, const int y) const {
    const char cell = get_cell(x, y);
    return islower(cell);
}

bool Grid::is_locked(const int x, const int y) const {
    const char cell = get_cell(x, y);
    return isalpha(cell);
}

Node::Node(const Cell& _pos, const int _keys) : pos(_pos), keys(_keys) {}

void Node::add_key(const char key) {
    const int num = (key - 'a') + 1; // Key number: a = 1, b = 2, ....
    keys |= (1 << num);
}

bool Node::have_key(const char key) const {
    const int num = (key - 'A') + 1; // Key number: A = 1, B = 2, ....
    return keys & (1 << num);
}
