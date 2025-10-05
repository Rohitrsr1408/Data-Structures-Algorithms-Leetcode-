class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& q, vector<vector<int>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        vector<int> xdir = {0, -1, 1, 0};
        vector<int> ydir = {-1, 0, 0, 1};

        while (!q.empty()) {
            auto p = q.front();
            int r = p.first;
            int c = p.second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newr = r + xdir[k];
                int newc = c + ydir[k];
                if (newr >= 0 && newr < m && newc >= 0 && newc < n &&
                    !visited[newr][newc] &&
                    heights[newr][newc] >= heights[r][c]) {
                    visited[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        queue<pair<int,int>> pacQ, atlQ;

        // Pacific border (top row + left column)
        for (int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            pacQ.push({i, 0});
        }
        for (int j = 0; j < n; j++) {
            pacific[0][j] = 1;
            pacQ.push({0, j});
        }

        // Atlantic border (bottom row + right column)
        for (int i = 0; i < m; i++) {
            atlantic[i][n-1] = 1;
            atlQ.push({i, n-1});
        }
        for (int j = 0; j < n; j++) {
            atlantic[m-1][j] = 1;
            atlQ.push({m-1, j});
        }

        // BFS from both oceans
        bfs(heights, pacQ, pacific);
        bfs(heights, atlQ, atlantic);

        // Collect intersection
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;