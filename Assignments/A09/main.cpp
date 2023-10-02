#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 25;

const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};

void bfs(int row, int col, vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        grid[r][c] = '0'; // Mark the cell as visited

        for (int i = 0; i < 8; ++i) {
            int newRow = r + dx[i];
            int newCol = c + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1') {
                q.push({newRow, newCol});
                grid[newRow][newCol] = '0'; // Mark the neighbor as visited
            }
        }
    }
}

int count_connected_components(vector<vector<char>>& grid) {
    n = grid.size();
    int components = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                bfs(i, j, grid);
                components++;
            }
        }
    }

    return components;
}

int main() {
  vector<vector<char>> grid(25, vector<char>(25));
    int size, it = 0;
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