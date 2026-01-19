#include "bits/stdc++.h"
using namespace std;

int BFS(int n, int m, int r, int c, vector<vector<int>>& maze) {
    // Các hướng di chuyển: lên, xuống, trái, phải
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    queue<pair<int, int>> q; // Queue đểlưutọađộ
    q.push({r, c});

    // Mảng 2 chiềukiểmtrađãghéthămchưa
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    visited[r][c] = true;

    int steps = 0; // Đếmsốbướcđãđi

    while (!q.empty()) {
        int size = q.size();
        steps++; // Tăngsốbướcsaumỗilầnlặp
        for (int i = 0; i< size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Kiểmtranếuđãra biên
            if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
                return steps; // Trảvềsốbước
            }

            // Kiểmtracác ô lâncận
            for (pair<int, int>direction : directions) {
                int new_x = x + direction.first;
                int new_y = y + direction.second;

                // Kiểmtraxem ô mớicóhợplệkhông
                if (new_x>= 0 &&new_x< n &&new_y>= 0 &&new_y< m &&
                    maze[new_x][new_y] == 0 && !visited[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                }
            }
        }
    }

    // Nếukhôngtìmthấyđườngthoát
    return -1;
}

int main() {
    int n, m, r, c;
    cin>> n >> m >> r >>c;
    r--; c--; // Chuyển sang chỉsố 0

    vector<vector<int>>maze(n, vector<int>(m)); // Sửdụng vector
    for (int i = 0; i< n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>> maze[i][j];
        }
    }

    cout<<BFS(n, m, r, c, maze) <<endl;
    return 0;
}

