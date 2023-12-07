#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Grid {
public:
    int x;
    int y;
    Grid* parent;
    int g;
    int h;
    int f;

    Grid(int x, int y) {
        this->x = x;
        this->y = y;
        this->parent = nullptr;
        this->g = 0;
        this->h = 0;
        this->f = 0;
    }

    void initGrid(Grid* parent, Grid* end) {
        this->parent = parent;
        this->g = parent ? parent->g + 1 : 1;
        this->h = abs(this->x - end->x) + abs(this->y - end->y);
        this->f = this->g + this->h;
    }
};

class FindMinGrid {
public:
    static const vector<vector<int>> MAZE;

    static Grid* aStarSearch(Grid* start, Grid* end) {
        vector<Grid*> openList;
        vector<Grid*> closeList;

        openList.push_back(start);

        while (!openList.empty()) {
            Grid* currentGrid = *min_element(openList.begin(), openList.end(),
                [](const Grid* a, const Grid* b) { return a->f < b->f; });

            openList.erase(remove(openList.begin(), openList.end(), currentGrid), openList.end());

            closeList.push_back(currentGrid);

            vector<Grid*> neighbors = findNeighbors(currentGrid, openList, closeList);

            for (Grid* grid : neighbors) {
                auto it = find(openList.begin(), openList.end(), grid);
                if (it == openList.end()) {
                    grid->initGrid(currentGrid, end);
                    openList.push_back(grid);
                } else {
                    if (grid->g > currentGrid->g + 1) {
                        grid->parent = currentGrid;
                        grid->g = currentGrid->g + 1;
                        grid->f = grid->g + grid->h;
                        *it = grid;
                    }
                }
            }

            for (Grid* grid : openList) {
                if (grid->x == end->x && grid->y == end->y) {
                    return grid;
                }
            }
        }

        return nullptr;
    }

    static vector<Grid*> findNeighbors(Grid* grid, vector<Grid*> openList, vector<Grid*> closeList) {
        vector<Grid*> gridList;

        int offsets[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

        for (const auto& offset : offsets) {
            int x = grid->x + offset[0];
            int y = grid->y + offset[1];

            if (isValidGrid(x, y, openList, closeList)) {
                gridList.push_back(new Grid(x, y));
            }
        }

        return gridList;
    }

    static bool isValidGrid(int x, int y, vector<Grid*> openList, vector<Grid*> closeList) {
        if (x < 0 || x >= MAZE.size() || y < 0 || y >= MAZE[0].size()) {
            return false;
        }

        if (MAZE[x][y] == 1) {
            return false;
        }

        for (Grid* grid : openList) {
            if (grid->x == x && grid->y == y) {
                return false;
            }
        }

        for (Grid* grid : closeList) {
            if (grid->x == x && grid->y == y) {
                return false;
            }
        }

        return true;
    }
};

const vector<vector<int>> FindMinGrid::MAZE = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

int main() {
    Grid* start = new Grid(2, 1);
    Grid* end = new Grid(2, 5);

    Grid* result = FindMinGrid::aStarSearch(start, end);

    vector<Grid*> path;
    while (result) {
        path.push_back(new Grid(result->x, result->y));
        result = result->parent;
    }

    for (int i = 0; i < FindMinGrid::MAZE.size(); ++i) {
        for (int j = 0; j < FindMinGrid::MAZE[0].size(); ++j) {
            bool isPath = any_of(path.begin(), path.end(),
                [i, j](const Grid* grid) { return grid->x == i && grid->y == j; });

            if (isPath) {
                cout << "* ";
            } else {
                cout << FindMinGrid::MAZE[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
