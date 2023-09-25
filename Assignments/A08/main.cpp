#include <iostream>
#include <vector>

using namespace std;

int n = 25; // Replace this with the actual size of the grid

void dfs(int row, int col, vector<vector<char>>& grid) {
    // Check if the current cell is outside the grid or is not part of the component
    if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] == '0') {
        return;
    }

    // Mark the current cell as visited by changing it to '0'
    grid[row][col] = '0';

    // Recursively visit all neighboring cells
    int dr[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dc[] = {0, 0, 1, -1, 1, -1, -1, 1};

    for (int i = 0; i < 8; i++) {
        dfs(row + dr[i], col + dc[i], grid);
    }
}

int count_connected_components(vector<vector<char>>& grid) {
    n = grid.size();
    int components = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(i, j, grid);
                components++;
            }
        }
    }

    return components;
}

int main() {
    vector<vector<char>> grid(25, vector<char>(25));
    int size, it;
    char x;

    while(cin >> size) {
        for (int i = 0; i < size; i++) {
            vector<int> row;
            for (int j = 0; j < size; j++) {
                cin >> x;
                grid[i][j] = x;
            }
        }

      it++;

      int components = count_connected_components(grid);
      cout << "Image number " << it << " contains " << components << " war eagles.\n";
    }
}