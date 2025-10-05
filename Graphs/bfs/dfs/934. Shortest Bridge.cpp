class Solution {
private:
    void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        vector<int> xdir = {-1,0,1,0};
        vector<int> ydir = {0,1,0,-1};
        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int newr = r + xdir[k];
                int newc = c + ydir[k];
                if (newr >= 0 && newr < grid.size() && newc >= 0 && newc < grid[0].size() &&
                    grid[newr][newc] == 1 && !visited[newr][newc]) {
                    q.push({newr,newc});
                    visited[newr][newc] = 1;
                }
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // ✅ mark the first island only once
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j, visited);
                    found = true;
                    break;
                }
            }
        }

        // Multi-source BFS from first island
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        vector<int> xdir = {-1,0,1,0};
        vector<int> ydir = {0,1,0,-1};
        int ans = -1;

        while (!q.empty()) {
            int size = q.size();
            ans++;
            for (int i = 0; i < size; i++) {
                auto [r,c] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int newr = r + xdir[k];
                    int newc = c + ydir[k];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc]) {
                        if (grid[newr][newc] == 1) return ans;  // found second island
                        q.push({newr, newc});
                        visited[newr][newc] = 1;
                    }
                }
            }
        }

        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;