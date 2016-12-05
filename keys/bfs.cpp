#include <iostream>
#include <queue>
#include <cstring>

#include "bfs.h"
#include "grid.h"

const int MAX_MASK_NUMBER = 1 << MASK_SIZE;
const int NOT_CALCULATED = -1;
const int NOT_FOUND = -1;

// X, Y helps navigating adjacent cells in the grid
const int X[] = {-1, 0, 1, 0};
const int Y[] = {0, 1, 0, -1};

const int MAX_GRID_SIZE = 123;

int dist[MAX_GRID_SIZE][MAX_GRID_SIZE][MAX_MASK_NUMBER];

int shortest_distance_start_goal(const Grid& grid) {

    clear_dist();

    const Cell start = grid.start;
    const Cell goal = grid.goal;
    queue<Node> q;
    q.push(Node(start, 0)); // Starts with no keys;
    dist[start.first][start.second][0] = 0;

    while(!q.empty()) {
        const Node u = q.front();
        q.pop();
        const int u_x = u.pos.first,
                  u_y = u.pos.second;
        const int u_d = dist[u_x][u_y][u.keys];

        // Goal was reached
        if(u.pos == goal) {
            return u_d;
        }

        for(int i = 0; i < 4; ++i) {
            // Cell (a, b) is the next being visited
            const int a = u_x + X[i];
            const int b = u_y + Y[i];
            if(!grid.valid(a, b))
                continue;

            Node ab(Cell(a, b), u.keys);
            const char cell_ab = grid.get_cell(a, b);

            if(grid.is_key(a, b)) {
                ab.add_key(cell_ab);
            }
            else if(grid.is_locked(a, b)) {
                if(not ab.have_key(cell_ab)) {
                    continue;
                }
            }
            if(dist[a][b][ab.keys] == NOT_CALCULATED) {
                dist[a][b][ab.keys] = u_d + 1;
                q.push(ab);
            }
        }
    }
    return NOT_FOUND;
}

// Sets every position of dist to be = NOT_CALCULATED
void clear_dist() {
    memset(dist, NOT_CALCULATED, sizeof dist);
}
